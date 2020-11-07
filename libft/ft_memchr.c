/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:59:27 by rmander           #+#    #+#             */
/*   Updated: 2020/11/07 11:59:28 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sc;
	
	if (!s || !n)
		return (NULL);
	sc = (unsigned char*)s;
	while (n--)
		if (*sc++ == (unsigned char)c)
			return (--sc);
	return (NULL);
}
