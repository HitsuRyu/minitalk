#include "libft.h"

static int	ft_movedown(char *dest, char *source, size_t len, size_t i)
{
	i = len - 1;
	while (i > 0)
	{
		dest[i] = source[i];
		i--;
	}
	dest[0] = source[0];
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	i;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (len == 0)
		return (dst);
	if (dest < source)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else if (dest > source)
	{
		ft_movedown(dest, source, len, i);
	}
	return (dst);
}
