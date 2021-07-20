#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"

struct	s_struct
{
	char	c;
	int		n;
};

struct s_struct	g_c;

void	handler(int sig)
{
	int		i;

	i = 0b10000000;
	if (sig == SIGUSR1)
	{
		g_c.c |= i >> g_c.n;
	}
	g_c.n++;
	if (g_c.n == 8)
	{
		if (g_c.c == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_c.c, 1);
		g_c.c = 0b0000000;
		g_c.n = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	g_c.c = 0b0000000;
	g_c.n = 0;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
}
