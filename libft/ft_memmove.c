#include <stdlib.h>

static void		*_ft_memmove_backward(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	
	d = dst;
	while (len--)
		*(d + len) = *(unsigned char*)(src + len);
	return (dst);
}

static void		*_ft_memmove_forward(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	
	d = dst;
	while (len--)
		*d++ = *(unsigned char*)src++;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	if (!src || !dst)
		return (NULL);
	if (src < dst)
		return (_ft_memmove_backward(dst, src, len));
	else if (src > dst)
		return (_ft_memmove_forward(dst, src, len));
	else
		return (dst);
}
