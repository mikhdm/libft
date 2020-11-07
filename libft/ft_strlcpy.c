/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:54:15 by rmander           #+#    #+#             */
/*   Updated: 2020/11/07 11:59:12 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	
	if (!src)
		return (0);
	srcsize = ft_strlen(src);
	if (!dst || !dstsize)
		return (srcsize);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (srcsize);
}
