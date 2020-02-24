/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils_three.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 16:05:15 by migalvar      #+#    #+#                 */
/*   Updated: 2020/02/22 19:14:55 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		ft_bigger_s(int width, int len, int precision)
{
	if (precision != -1 && precision >= width && precision < len)
		return (precision);
	if (width >= len)
		return (width);
	if (width < len && precision < len && precision != -1)
		return (width);
	return (len);
}

char	*ft_hd_str(char type)
{
	if (type == 'x' || type == 'p' || type == 'u')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

void	ft_putnbr_x(unsigned long n, char type, int precision)
{
	char	*hd;
	char	out[256];
	int		i;

	i = ft_count_x(n, precision);
	hd = ft_hd_str(type);
	if (n == 0 && precision != 0)
	{
		ft_putchar('0');
		return ;
	}
	out[i] = '\0';
	i--;
	while (i >= 0)
	{
		out[i] = hd[n % 16];
		n = n / 16;
		i--;
	}
	ft_putstr(out);
}
