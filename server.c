#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_struct
{
	char	byte;
	int		offset;
	char	*str;
}				t_info;

t_info	g_info;

void	stringconstructor(t_info *g_info)
{
	char	*tmp;
	char	*tmp2;

	if (g_info->byte == '\0')
	{
		tmp = g_info->str;
		g_info->str = ft_strjoin(g_info->str, "\n");
		free(tmp);
		write(1, g_info->str, ft_strlen(g_info->str));
	}
	else
	{
		tmp = g_info->str;
		tmp2 = ft_substr(&g_info->byte, 0, 1);
		g_info->str = ft_strjoin(g_info->str, tmp2);
		free(tmp);
		free(tmp2);
	}
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	int		i;

	i = 0b10000000;
	if (sig == SIGUSR1)
		g_info.byte |= i >> g_info.offset;
	g_info.offset++;
	if (g_info.offset == 8)
	{
		stringconstructor(&g_info);
		g_info.offset = 0;
		g_info.byte = 0b00000000;
	}
	usleep(30);
	kill(siginfo->si_pid, SIGUSR1);
	context = NULL;
}

int	main(void)
{
	char				*pid;
	struct sigaction	act;

	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
