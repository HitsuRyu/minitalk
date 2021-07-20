#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)s);
	i = 0;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
