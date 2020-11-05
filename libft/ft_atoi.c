#include "libft.h"

short int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

long	ft_pow(long n, long power)
{
	long	res;

	res = 1;
	while (power--)
		res *= n;
	return (res);
}

int		ft_atoi(const char *str)
{
	long		result;
	const char	*end;
	int			neg;
	int			count;
	int			i;

	neg = 0;
	result = 0;
	count = 0;
	i = 0;
	if (*str == '-')
	{
		str++;
		neg = 1;
	}
	end = str;
	while (*end && ft_is_numeric(*end))
	{
		count++;
		end++;
	}
	end--;
	while (i < count)
		result += (*end-- - '0') * ft_pow(10, i++);
	return ((int)((neg) ? result * (-1) : result));
}
