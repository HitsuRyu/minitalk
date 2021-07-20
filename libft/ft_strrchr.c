#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	*last;

	last = NULL;
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
			last = str + i;
		}
		i++;
	}
	return (last);
}
