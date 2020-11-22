/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:15:24 by rmander           #+#    #+#             */
/*   Updated: 2020/11/22 15:12:57 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include "libft.h"

# undef INT_MIN
# undef INT_MAX

#include <limits.h>

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

	char	c2 = '9';
	char	src2[] = "9876543210";
	char	dst2[] = "0123456789";
	size_t	n2 = 9;
	char	*d2;

	c = 'a';
	n = 10;
	d = NULL;
	printf("basic 1:\n");
	printf("system:\n");
	d = memccpy(dst, src, c, n);
	--d;
	printf("%c\n", *d);
	printf("mine:\n");
	d1 = ft_memccpy(dst1, src1, c, n);
	--d1;
	printf("%c\n", *d1);

	printf("basic 2 (moulinette):\n");
	printf("system:\n");
	/* 123456789 */
	d2 = memccpy(dst2, src2, c2, n2);
	printf("%s\n", d2);
	printf("mine:\n");
	d2 = ft_memccpy(dst2, src2, c2, n2);
	printf("%s\n", d2);
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

void	ft_test_memchr()
{
	char s[] = "abcde";
	int c = 'e';
	size_t n = 5;

	printf("basic 1:\n");
	printf("system:\n");
	printf("%c\n", *(unsigned char*)memchr(s, c, n));
	printf("mine:\n");
	printf("%c\n", *(unsigned char*)ft_memchr(s, c, n));
}

void	ft_test_memcmp()
{
	char	s1[] = "hello";
	char	s2[] = "hello";
	char	s3[] = "abcd0";
	char	s4[] = "abcd5";
	size_t	n = 5;

	printf("basic 1 (equal):\n");
	printf("system:\n");
	printf("%s == %s ? %d\n", s1, s2, memcmp(s1, s2, n));
	printf("mine:\n");
	printf("%s == %s ? %d\n", s1, s2, ft_memcmp(s1, s2, n));

	printf("basic 2 (non equal):\n");
	printf("system:\n");
	printf("%s == %s ? %d\n", s3, s4, memcmp(s3, s4, n));
	printf("mine:\n");
	printf("%s == %s ? %d\n", s3, s4, ft_memcmp(s3, s4, n));
}

void	ft_test_strlen()
{
	char s[] = "hello";
	printf("system:\n");
	printf("%zu\n", strlen(s));
	printf("mine:\n");
	printf("%zu\n", ft_strlen(s));
}

void	ft_test_strlcpy()
{
	size_t	dstsize = 6;

	char	s[] = "hello";
	char	d[6];

	char	s1[] = "hello";
	char	d1[6];
	printf("system:\n");
	printf("%zu ", strlcpy(d, s, dstsize));
	printf("%s\n", d);
	printf("mine:\n");
	printf("%zu ", ft_strlcpy(d1, s1, dstsize));
	printf("%s\n", d1);
}

void	ft_test_strlcat()
{
	size_t	dstsize = 11;

	char	s[] = "12345";
	char	d[11] = "abcde";

	char	s1[] = "12345";
	char	d1[11] = "abcde";
	
	printf("basic 1:\n");
	printf("system:\n");
	printf("%zu\n", strlcat(d, s, dstsize));
	printf("%s\n", d);
	printf("mine:\n");
	printf("%zu\n", ft_strlcat(d1, s1, dstsize));
	printf("%s\n", d);

	printf("libft-unit-test 1:\n");\
	char	*src = "aaa";
	char	dst1[20];
	char	dst2[20];
	int		ret1;
	int		ret2;

	memset(dst1, 'B', sizeof(dst1));
	memset(dst2, 'B', sizeof(dst2));

	strlcat(dst1, src, 20);
	strlcat(dst1, src, 20);
	ret1 = strlcat(dst1, src, 20);

	ft_strlcat(dst2, src, 20);
	ft_strlcat(dst2, src, 20);
	ret2 = ft_strlcat(dst2, src, 20);
}

void	ft_test_strchr()
{
	char 	s[] = "hello1";
	int		c = '1';
	char	*r1;
	char	*r2;

	printf("system:\n");
	r1 = strchr(s, c);
	printf("%c\n", *r1);
	printf("mine:\n");
	r2 = ft_strchr(s, c);
	printf("%c\n", *r2);
}

void	ft_test_strrchr()
{
	char 	s[] = "1hello";
	int		c = '1';
	char	*r1;
	char	*r2;

	printf("system:\n");
	r1 = strchr(s, c);
	printf("%c\n", *r1);
	printf("mine:\n");
	r2 = ft_strrchr(s, c);
	printf("%c\n", *r2);
}

void	ft_test_strnstr()
{
	size_t	len = 14;

	char	haystack[] = "bbbc";
	char	needle[] = "bbc";

	char	haystack1[] = "bbbc";
	char	needle1[] = "bbc";

	printf("system:\n");
	printf("%s\n", strnstr(haystack, needle, 4));
	printf("mine:\n");
	printf("%s\n", ft_strnstr(haystack1, needle1, 4));
}

void	ft_test_strncmp()
{
	char	s1[] = "hello";
	char	s2[] = "hell2";
	size_t	n = 4;

	printf("system:\n");
	printf("n = %zu, %s == %s ? %d\n", n, s1, s2, strncmp(s1, s2, n));
	printf("mine:\n");
	printf("n = %zu, %s == %s ? %d\n", n, s1, s2, ft_strncmp(s1, s2, n));
}

void	ft_test_atoi()
{
	char 	*d1 = "-11123";
	char	*d2 = "111aaa";
	char	*d3 = "2147483648";
	char	*d4 = "-2147483649";

	printf("basic 1:\n");
	printf("system:\n");
	printf("%s: %d\n", d1, atoi(d1));
	printf("mine:\n");
	printf("%s: %d\n", d1, ft_atoi(d1));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%s: %d\n", d2, atoi(d2));
	printf("mine:\n");
	printf("%s: %d\n", d2, ft_atoi(d2));

	printf("basic 3:\n");
	printf("system:\n");
	printf("%s: %d\n", d3, atoi(d3));
	printf("mine:\n");
	printf("%s: %d\n", d3, ft_atoi(d3));

	printf("basic 4:\n");
	printf("system:\n");
	printf("%s: %d\n", d4, atoi(d4));
	printf("mine:\n");
	printf("%s: %d\n", d4, ft_atoi(d4));
}

void	ft_test_isalpha()
{
	int	c = 'c';
	int	d = '1';

	printf("basic 1:\n");
	printf("system:\n");
	printf("%c: %d\n", c, isalpha(c));
	printf("mine:\n");
	printf("%c: %d\n", c, ft_isalpha(c));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%c: %d\n", d, isalpha(d));
	printf("mine:\n");
	printf("%c: %d\n", d, ft_isalpha(d));
}

void	ft_test_isdigit()
{
	int c = 'a';
	int	d = '1';

	printf("basic 1:\n");
	printf("system:\n");
	printf("%c: %d\n", c, isdigit(c));
	printf("mine:\n");
	printf("%c: %d\n", c, ft_isdigit(c));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%c: %d\n", d, isdigit(d));
	printf("mine:\n");
	printf("%c: %d\n", d, ft_isdigit(d));
}

void	ft_test_isalnum()
{
	int	c1 = '1';
	int	c2 = 'a';
	int	c3 = '~';

	printf("basic 1:\n");
	printf("system:\n");
	printf("%c: %d\n", c1, isalnum(c1));
	printf("mine:\n");
	printf("%c: %d\n", c1, ft_isalnum(c1));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%c: %d\n", c2, isalnum(c2));
	printf("mine:\n");
	printf("%c: %d\n", c2, ft_isalnum(c2));

	printf("basic 3:\n");
	printf("system:\n");
	printf("%c: %d\n", c3, isalnum(c3));
	printf("mine:\n");
	printf("%c: %d\n", c3, ft_isalnum(c3));
}

void	ft_test_isascii()
{
	int	c = '~';
	int	d = 290;

	printf("basic 1:\n");
	printf("system:\n");
	printf("%c: %d\n", c, isascii(c));
	printf("mine:\n");
	printf("%c: %d\n", c, ft_isascii(c));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%d: %d\n", d, isascii(d));
	printf("mine:\n");
	printf("%d: %d\n", d, ft_isascii(d));
}

void	ft_test_isprint()
{
	int	c = '\0';
	int	d = 'a';

	printf("basic 1:\n");
	printf("system:\n");
	printf("nul-term: %d\n", isprint(c));
	printf("mine:\n");
	printf("nul-term: %d\n", ft_isprint(c));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%c: %d\n", d, isprint(d));
	printf("mine:\n");
	printf("%c: %d\n", d, ft_isprint(d));

}

/* void	ft_test_isupper() */
/* { */
/* 	int	c = 'a'; */
/* 	int	d = 'Z'; */

/* 	printf("basic 1:\n"); */
/* 	printf("system:\n"); */
/* 	printf("%c: %d\n", c, isupper(c)); */
/* 	printf("mine:\n"); */
/* 	printf("%c: %d\n", c, ft_isupper(c)); */

/* 	printf("basic 2:\n"); */
/* 	printf("system:\n"); */
/* 	printf("%c: %d\n", d, isupper(d)); */
/* 	printf("mine:\n"); */
/* 	printf("%c: %d\n", d, ft_isupper(d)); */
/* } */

/* void	ft_test_islower() */
/* { */
/* 	int	c = 'a'; */
/* 	int	d = 'Z'; */

/* 	printf("basic 1:\n"); */
/* 	printf("system:\n"); */
/* 	printf("%c: %d\n", c, islower(c)); */
/* 	printf("mine:\n"); */
/* 	printf("%c: %d\n", c, ft_islower(c)); */

/* 	printf("basic 2:\n"); */
/* 	printf("system:\n"); */
/* 	printf("%c: %d\n", d, islower(d)); */
/* 	printf("mine:\n"); */
/* 	printf("%c: %d\n", d, ft_islower(d)); */

/* } */

void	ft_test_toupper()
{
	int	c = 'a';
	int	d = 'Z';

	printf("basic 1:\n");
	printf("system:\n");
	printf("%c: %c\n", c, toupper(c));
	printf("mine:\n");
	printf("%c: %c\n", c, ft_toupper(c));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%c: %c\n", d, toupper(d));
	printf("mine:\n");
	printf("%c: %c\n", d, ft_toupper(d));

}

void	ft_test_tolower()
{
	int	c = 'a';
	int	d = 'Z';

	printf("basic 1:\n");
	printf("system:\n");
	printf("%c: %c\n", c, tolower(c));
	printf("mine:\n");
	printf("%c: %c\n", c, ft_tolower(c));

	printf("basic 2:\n");
	printf("system:\n");
	printf("%c: %c\n", d, tolower(d));
	printf("mine:\n");
	printf("%c: %c\n", d, ft_tolower(d));
}

void	ft_test_calloc()
{
	char	*mem;
	size_t	i;

	printf("basic 1:\n");
	printf("system:\n");
	mem = calloc(10, sizeof(char));
	i = 0;
	while (i < 10)
		if (mem[i++] == 0)
			printf("0");
	printf("\n");
	free(mem);

	printf("mine:\n");
	mem = ft_calloc(10, sizeof(char));
	i = 0;
	while (i < 10)
		if (mem[i++] == 0)
			printf("0");
	printf("\n");
	free(mem);
}

void	ft_test_strdup()
{
	char	src[] = "abcdef";
	char	*dst1;
	char	*dst2;

	printf("basic 1:\n");
	printf("system:\n");
	dst1 = strdup(src);
	printf("%s\n", dst1);
	printf("mine:\n");
	dst2 = ft_strdup(src);
	printf("%s\n", dst2);
	free(dst1);
	free(dst2);
}

void	ft_test_substr()
{
	char			src[] = "abcdefgh";
	size_t			len = 5;
	unsigned int	start = 0;
	size_t			len1 = 0;
	unsigned int	start1 = 0;

	printf("basic 1:\n");
	printf("src: %s, start: %u len: %zu, %s\n", src, start, len, ft_substr(src, start, len));
	printf("basic 2:\n");
	printf("src: %s, start: %u len: %zu, %s\n", src, start1, len1, ft_substr(src, start1, len1));
}

void	ft_test_strjoin()
{
	char	s1[] = "abc";
	char	s2[] = "defg";
	char	s3[] = "";
	char	*r;

	printf("basic 1:\n");
	r = ft_strjoin(s1, s2);
	printf("s1: %s, s2: %s, %s\n", s1, s2, r);
	printf("basic 1:\n");
	r = ft_strjoin(s3, s3);
	printf("two empties, slash-zero? %d\n", *r == '\0');
}

void	ft_test_strtrim()
{
	char	set[] = ".!";
	char	s1[] = ".!!!!!!.!!!A!";
	char	*result;

	printf("basic 1:\n");
	result = ft_strtrim(s1, set);
	printf("s1: %s, set: %s, result: %s\n", s1, set, result);
}

void	ft_test_split()
{
	char	str[] = "this peace of paper    should be cut    ";
	char	**strs;

	printf("basic 1:\n");
	strs = ft_split(str, ' ');
	printf("\n");
	printf("input: <%s>\n", str);
	printf("\n");
	printf("output:\n");
	while (*strs)
		printf("<%s>\n", *strs++);   

	printf("basic 2:\n");
	char 	str2[] = "    ";
	char	**strs2;
	int		i;
	
	i = 0;
	strs2 = ft_split(str2, ' ');
	printf("<%s>\n", strs2[0]);
	printf("%s\n", strs2[1]);
}

void	ft_test_itoa()
{
	printf("basic 1:\n");
	printf("n: %d (INT_MIN), result: %s\n", INT_MIN, ft_itoa(INT_MIN)); 

	printf("basic 2:\n");
	printf("n: %d, result: %s\n", -12345, ft_itoa(-12345)); 

	printf("basic 3:\n");
	printf("n: %d, result: %s\n", 12345, ft_itoa(12345)); 

	printf("basic 4:\n");
	printf("n: %d (INT_MAX), result: %s\n", INT_MAX, ft_itoa(INT_MAX)); 
	printf("basic 5:\n");
	printf("n: %d, result: %s\n", 0, ft_itoa(0)); 
}


char	ft_to_upperi(unsigned int i, char c)
{
	if (i % 2 == 0)
		if (islower(c))
			c= c - 32;
	return (c);
}

void	ft_test_strmapi()
{
	char	data[] = "abcdefgh";
	printf("basic 1:\n");
	printf("str: %s, output: %s\n", data, ft_strmapi(data, &ft_to_upperi));
}

void	ft_test_putchar_fd()
{
	printf("basic 1:\n");
	ft_putchar_fd('a', 0);
	ft_putchar_fd('b', 0);
	ft_putchar_fd('c', 0);
	ft_putchar_fd('\n', 0);
	printf("basic 2:\n");
	ft_putchar_fd('d', -1);
}

void	ft_test_putstr_fd()
{
	printf("basic 1:\n");
	ft_putstr_fd("hello ", 0);
	ft_putstr_fd("beautiful ", 0);
	ft_putstr_fd("world", 0);
	ft_putchar_fd('\n', 0);
	printf("basic 2:\n");
	ft_putstr_fd("world", -1);

}

void	ft_test_putendl_fd()
{
	printf("basic 1:\n");
	ft_putendl_fd("<hello>", 0);
	ft_putendl_fd("<beautiful>", 0);
	ft_putendl_fd("<world>", 0);
	printf("basic 2:\n");
	ft_putendl_fd("<world>", -1);

}

void	ft_test_putnbr_fd()
{
	printf("basic 1:\n");
	ft_putnbr_fd(INT_MAX, 0);
	ft_putchar_fd('\n', 0);
	printf("basic 2:\n");
	ft_putnbr_fd(INT_MIN, 0);
	ft_putchar_fd('\n', 0);
	printf("basic 3:\n");
	ft_putnbr_fd(-12340, 0);
	ft_putchar_fd('\n', 0);
	printf("basic 4:\n");
	ft_putnbr_fd(12340, 0);
	ft_putchar_fd('\n', 0);
	printf("basic 5:\n");
	ft_putnbr_fd(0, 0);
	ft_putchar_fd('\n', 0);
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
	printf("PART 1:\n");
	test("FT_MEMSET", &ft_test_memset);
	test("FT_BZERO", &ft_test_bzero);
	test("FT_MEMCPY", &ft_test_memcpy);
	test("FT_MEMCCPY", &ft_test_memccpy);
	test("FT_MEMMOVE", &ft_test_memmove);
	test("FT_MEMCHR", &ft_test_memchr);
	test("FT_MEMCMP", &ft_test_memcmp);
	test("FT_STRLEN", &ft_test_strlen);
	test("FT_STRLCPY", &ft_test_strlcpy);
	test("FT_STRLCAT", &ft_test_strlcat);
	test("FT_STRCHR", &ft_test_strchr);
	test("FT_STRRCHR", &ft_test_strrchr);
	test("FT_STRNSTR", &ft_test_strnstr);
	test("FT_STRNCMP", &ft_test_strncmp);
	test("FT_ATOI", &ft_test_atoi);
	test("FT_ISALPHA", &ft_test_isalpha);
	test("FT_ISIDIGIT", &ft_test_isdigit);
	test("FT_ISALNUM", &ft_test_isalnum);
	test("FT_ISASCII", &ft_test_isascii);
	test("FT_ISPRINT", &ft_test_isprint);
	/* test("FT_ISUPPER", &ft_test_isupper); */
	/* test("FT_ISLOWER", &ft_test_islower); */
	test("FT_TOUPPER", &ft_test_toupper);
	test("FT_TOLOWER", &ft_test_tolower);
	test("FT_CALLOC", &ft_test_calloc);
	test("FT_STRDUP", &ft_test_strdup);

	printf("\n");
	printf("PART 2:\n");
	printf("\n");

	test("FT_SUBSTR", &ft_test_substr);
	test("FT_STRJOIN", &ft_test_strjoin);
	test("FT_STRTRIM", &ft_test_strtrim);
	test("FT_SPLIT", &ft_test_split);
	test("FT_ITOA", &ft_test_itoa);
	test("FT_STRMAPI", &ft_test_strmapi);
	test("FT_PUTCHAR_FD", &ft_test_putchar_fd); 
	test("FT_PUTSTR_FD", &ft_test_putstr_fd); 
	test("FT_PUTENDL_FD", &ft_test_putendl_fd); 
	test("FT_PUTNBR_FD", &ft_test_putnbr_fd); 

	return (0);
}
