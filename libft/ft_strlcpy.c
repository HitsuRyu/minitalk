#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	char	*source;

	i = 0;
	source = (char *)src;
	if (dstsize == 0)
	{
		return (ft_strlen(source));
	}
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(source));
}
