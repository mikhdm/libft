/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:09:56 by rmander           #+#    #+#             */
/*   Updated: 2020/11/07 19:14:21 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isalpha_lower(int c)
{
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return (TRUE);
	return (FALSE);
}

static int	ft_isalpha_upper(int c)
{
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z') 
		return (TRUE);
	return (FALSE);
}

int		ft_isalpha(int c)
{
	if (ft_isalpha_lower(c) || ft_isalpha_upper(c))
		return (TRUE);
	return (FALSE);
}
