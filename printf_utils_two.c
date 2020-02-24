/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils_two.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:46:51 by migalvar      #+#    #+#                 */
/*   Updated: 2020/02/22 18:22:42 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnbr(int n, int precision)
{
	if (n == 0 && precision == 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr("2147483648");
		return ;
	}
	if (n < 0)
		n = n * (-1);
	if ((n / 10) > 0)
		ft_putnbr((n / 10), precision);
	ft_putchar((n % 10) + '0');
}

int			ft_print_fill(int i, char direction, char fill)
{
	ft_putchar(fill);
	if (direction == '-')
		i--;
	else
		i++;
	return (i);
}

int			ft_i_len(int w, int p, int c)
{
	if (w > p && w > c)
		return (w);
	if (p > c)
		return (p);
	return (c);
}

int			ft_count_n(int n, int precision)
{
	int		i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0 && precision != 0)
		i++;
	else if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int			ft_count_x(unsigned long n, int precision)
{
	int		i;

	i = 0;
	if (n == 0 && precision != 0)
		i++;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
