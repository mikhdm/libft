/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:06:16 by rmander           #+#    #+#             */
/*   Updated: 2020/11/07 17:07:51 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strstr(const char *haystack, const char *needle, const char *end)
{
	char	*str;
	char	*key;

	while (haystack != end)
	{
		str = (char*)haystack;
		key = (char*)needle;
		while ((str != end) && *key)
		{
			if (*str != *key)
				break ;
			++str;
			++key;
		}
		if (!*key)
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*end;
	size_t	haystacksize;
	char	*substr;
	
	if (!*needle)
		return ((char*)haystack);
	if (!len)
		return (NULL);
	haystacksize = ft_strlen(haystack);
	end = (char*)((len < haystacksize) ? (haystack + len): (haystack + haystacksize));
	if ((substr = ft_strstr(haystack, needle, end)))
			return (substr);
	return (NULL);
}
