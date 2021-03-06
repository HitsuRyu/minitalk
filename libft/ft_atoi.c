#include "libft.h"

int	ft_atoi(char *str)
{
	int		i;
	int		n;
	char	sign;

	i = 0;
	n = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
	{
		i++;
	}
	if (str[i] != '-' && (str[i] < '0' || str[i] > '9') && str[i] != '+')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i];
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (sign == '-')
		n = n * (-1);
	return (n);
}
