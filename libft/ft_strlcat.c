/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:54:40 by rmander           #+#    #+#             */
/*   Updated: 2020/11/13 23:37:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	dstsize_init;

	dstsize_init = ft_strlen(dst);
	srcsize = ft_strlen(src);
	dst += dstsize_init;
	if (dstsize_init && (dstsize_init > dstsize))
		return (dstsize_init + srcsize);
	dst -= dstsize_init;
	while (dstsize-- && *src) 
		*dst++ = *src++;
	*dst = '\0';
	return (dstsize_init + srcsize);
}
