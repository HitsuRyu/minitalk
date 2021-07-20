#include "libft.h"

void	*ft_memccpy(void *restrict dst, \
const void *restrict src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
		{
			dest[i] = source[i];
			return (dest + i + 1);
		}
		dest[i] = source[i];
		i++;
	}
	return (NULL);
}
