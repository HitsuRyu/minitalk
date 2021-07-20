#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL && n != 0)
		return (NULL);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
