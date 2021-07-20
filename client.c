#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		pid;
	size_t	len;

	if (argc != 3)
	{
		write(1, "error", 5);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(argv[2]) + 1;
	while (len--)
	{
		i = 0b10000000;
		while (i > 0)
		{
			if (i & *str)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i = i >> 1;
			usleep(150);
		}
		str++;
	}
}
