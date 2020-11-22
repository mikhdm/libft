/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:00:17 by rmander           #+#    #+#             */
/*   Updated: 2020/11/22 22:17:14 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	ssize;

	ssize = ft_strlen(s);
	substr = NULL;
	if (start >= ssize)
		return (ft_strdup(""));
	if (len > (ssize - start))
		len = ssize - start;
	if (!len)
		return (ft_strdup(""));
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
