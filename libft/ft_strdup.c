#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((char *)s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
