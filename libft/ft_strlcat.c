/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:54:40 by rmander           #+#    #+#             */
/*   Updated: 2020/11/07 11:59:14 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	dstsize_init;

	dstsize_init = 0;
	if (dst)
		dstsize_init = ft_strlen(dst);
	if (!src)
		return (dstsize_init);
	srcsize = ft_strlen(src);
	if (!dst)
		return (srcsize);
	dst = dst + dstsize_init;
	dstsize = dstsize - dstsize_init - 1;
	if (dstsize < 0)
		return (dstsize_init + srcsize);
	while (dstsize-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dstsize_init + srcsize);
}
