/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils_three.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:29:15 by migalvar      #+#    #+#                 */
/*   Updated: 2020/02/22 18:35:36 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_print_c(t_var *info, int c)
{
	char	d;
	int		i;

	i = 1;
	d = (char)c;
	if (info->width > 1)
	{
		if (info->flag_m == 1)
			ft_putchar(d);
		while (i < info->width && info->flag_z == 0)
			i = ft_print_fill(i, '+', ' ');
		if (info->flag_m == 0)
			ft_putchar(d);
	}
	else
		ft_putchar(d);
	return (i);
}

int				ft_print_s(t_var *info, char *s, int i, int k)
{
	int		j;
	int		l;
	int		m;

	j = ft_bigger_s(info->width, ft_strlen(s), info->pr);
	l = ft_strlen(s);
	m = 0;
	if (info->pr < l && info->pr > -1)
		l = info->pr;
	while (i < j)
	{
		while (info->flag_m == 0 && i < (j - l))
			i = ft_print_fill(i, '+', ' ');
		if (i != j && l != 0)
		{
			ft_putchar(s[k]);
			i++;
			k++;
		}
		while (k == l && m < (j - i))
			m = ft_print_fill(m, '+', ' ');
		i = i + m;
	}
	return (i);
}

int				ft_print_i(t_var *info, int n)
{
	int		i;
	int		j;
	int		k;

	i = ft_count_n(n, info->pr);
	j = ft_i_len(info->width, info->pr, i);
	k = info->pr;
	if (k == -1 || i > k)
		k = i;
	if (n < 0 && (info->pr >= ft_count_n(n, info->pr)))
		k++;
	while (j > k && (info->flag_z == 0 || info->pr > 0) && info->flag_m == 0)
	{
		k = ft_print_fill(k, '+', ' ');
		i++;
	}
	if (n < 0)
		ft_putchar('-');
	while ((j > i && (info->flag_z == 1 && info->pr != 0)) || k > i)
		i = ft_print_fill(i, '+', '0');
	ft_putnbr(n, info->pr);
	while (j > i && (info->flag_z == 0 || info->pr == 0))
		i = ft_print_fill(i, '+', ' ');
	return (i);
}

int				ft_print_x(t_var *info, unsigned int x)
{
	int		i;
	int		j;
	int		k;

	i = ft_count_x(x, info->pr);
	j = ft_i_len(info->width, info->pr, i);
	k = info->pr;
	if (k == -1 || i > k)
		k = i;
	while (j > k && (info->flag_z == 0 || info->pr > 0) && info->flag_m == 0)
	{
		k = ft_print_fill(k, '+', ' ');
		i++;
	}
	while ((j > i && (info->flag_z == 1 && info->pr != 0)) || k > i)
		i = ft_print_fill(i, '+', '0');
	ft_putnbr_x((unsigned long)x, info->type, info->pr);
	while (j > i && (info->flag_z == 0 || info->pr == 0))
		i = ft_print_fill(i, '+', ' ');
	return (i);
}

int				ft_print_p(t_var *info, void *p)
{
	unsigned long	as;
	int				i;
	int				j;
	int				k;

	as = (unsigned long)p;
	i = 2 + ft_count_x(as, info->pr);
	j = ft_i_len(info->width, info->pr, i);
	k = info->pr;
	if (k == -1 || i > k)
		k = i;
	while (j > k && (info->flag_z == 0 || info->pr > 0) && info->flag_m == 0)
	{
		k = ft_print_fill(k, '+', ' ');
		i++;
	}
	write(1, "0x", 2);
	while ((j > i && info->flag_z == 1) || k > i)
		i = ft_print_fill(i, '+', '0');
	ft_putnbr_x(as, info->type, info->pr);
	while (j > i && info->flag_z == 0)
		i = ft_print_fill(i, '+', ' ');
	return (i);
}
