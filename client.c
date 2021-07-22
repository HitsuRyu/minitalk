#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"

int	g_i;

void	ft_nextbit(int sig)
{
	g_i = g_i >> 1;
	sig = SIGUSR1;
	usleep(30);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	len;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]) + 1;
	signal(SIGUSR1, ft_nextbit);
	while (len--)
	{
		g_i = 0b10000000;
		while (g_i)
		{
			if (g_i & *argv[2])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
		}
		argv[2]++;
	}
}
