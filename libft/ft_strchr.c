#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (c == '\0')
	{
		return (str + ft_strlen(str));
	}
	while (str[i])
	{
		if (str[i] == c)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
