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

void	ft_test_memmove()
{
	char	s1[] = "abcdefg";
	char	d1[7];
	char	*r1;
	size_t	len1;
	size_t	i;

	char	s2[] = "abcdefg";
	char	d2[7];
	char	*r2;
	size_t	len2;

	len1 = 7;
	len2 = 5;
	r1 = NULL;
	r2 = NULL;
	ft_putstr("basic 1:\n");

	ft_putstr("system:\n");
	r1 = memmove(d1, s1, len1);
	i = 0;
	while (i < len1)
		ft_putchar(r1[i++]);

	ft_putstr("\nmine:\n");
	r2 = ft_memmove(d2, s2, len1);
	i = 0;
	while (i < len1)
		ft_putchar(r2[i++]);

	ft_putstr("\nbasic 2 (overlapping):\n");

	ft_putstr("system:\n");
	r1 = memmove(s1 + 2, s1, len2);
	i = 0;
	while (i < len2)
		ft_putchar(r1[i++]);

	ft_putstr("\nmine:\n");
	r2 = ft_memmove(s2 + 2, s2, len2);
	i = 0;
	while (i < len2)
		ft_putchar(r2[i++]);
	ft_putchar('\n');
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
	test("FT_MEMMOVE", &ft_test_memmove);

	return (0);
}
