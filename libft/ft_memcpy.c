#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	
	d = (unsigned char*)dst;
	if (!dst || !src)
		return (NULL);
	while (n--)
		*d++ = *(unsigned char*)src++;
	return (dst);
}
