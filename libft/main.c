/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:15:24 by rmander           #+#    #+#             */
/*   Updated: 2020/11/04 01:28:34 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_test_memset()
{
	char	orig_data[10];
	char	my_data[10];
	int		i;

	memset(orig_data, 'e', 10); 
	ft_memset(my_data, 'e', 10);

	ft_putstr("system:\n");
	i = 0;
	while (i < 10)
		ft_putchar(orig_data[i++]);
	ft_putchar('\n');

	ft_putstr("mine:\n");
	i = 0;
	while (i < 10)
		ft_putchar(my_data[i++]);
	ft_putchar('\n');
}

void	ft_test_memcpy()
{
	int		i;
	char	dst1[10];
	char	src1[] = "0123456789";
	char	*dst_result1;
	char	dst2[10];
	char	src2[] = "0123456789";
	char	*dst_result2;

	ft_putstr("system:\n");
	dst_result1 = memcpy(dst1, src1, 10); 
	i = 0;
	while (i < 10)
		ft_putchar(dst_result1[i++]);
	ft_putchar('\n');

	ft_putstr("mine:\n");
	dst_result2 = ft_memcpy(dst2, src2, 10);
	i = 0;
	while (i < 10)
		ft_putchar(dst_result2[i++]);
	ft_putchar('\n');
}

void	ft_test_bzero()
{
	int		i;
	char	data1[10];
	char	data2[10];

	ft_putstr("system:\n");
	bzero(data1, 10);
	i = 0;
	while (i < 10)
		if (!data1[i++])
			ft_putchar('0');
	ft_putchar('\n');

	ft_putstr("mine:\n");
	ft_bzero(data2, 10);
	i = 0;
	while (i < 10)
		if (!data2[i++])
			ft_putchar('0');
	ft_putchar('\n');
}

void	ft_test_memccpy()
{
	int		c;
	size_t	n;
	char	src[] = "01234a6789";
	char	dst[10];
	char	src1[] = "01234a6789";
	char	dst1[10];
	char	*d;
	char	*d1;

	c = 'a';
	n = 10;
	d = NULL;
	ft_putstr("system:\n");
	d = memccpy(dst, src, 'a', 10);
	--d;
	ft_putchar(*d);
	ft_putchar('\n');
	ft_putstr("mine:\n");
	d1 = ft_memccpy(dst1, src1, 'a', 10);
	--d1;
	ft_putchar(*d1);
	ft_putstr("\n");
}

void	test(char *name, void (*func)(void))
{
	ft_putstr(name);
	ft_putchar('\n');
	ft_putstr("---------------\n");
	func();
	ft_putstr("---------------\n\n");
}

int		main(void)
{
	test("FT_MEMSET", &ft_test_memset);
	test("FT_BZERO", &ft_test_bzero);
	test("FT_MEMCPY", &ft_test_memcpy);
	test("FT_MEMCCPY", &ft_test_memccpy);

	return (0);
}
