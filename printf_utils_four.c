/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils_three.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 18:29:15 by migalvar      #+#    #+#                 */
/*   Updated: 2020/02/22 18:33:58 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_print_percent(t_var *info, char c)
{
	int		i;

	i = 1;
	if (info->width > 1)
	{
		if (info->flag_m == 1)
			ft_putchar(c);
		while (i < info->width && info->flag_z == 0)
			i = ft_print_fill(i, '+', ' ');
		while (i < info->width && (info->flag_z == 0 || info->flag_m == 1))
			i = ft_print_fill(i, '+', ' ');
		while (i < info->width && info->flag_z == 1 && info->flag_m == 0)
			i = ft_print_fill(i, '+', '0');
		if (info->flag_m == 0)
			ft_putchar(c);
	}
	else
		ft_putchar(c);
	return (i);
}

void			ft_putnbr_u(unsigned int u, int precision)
{
	if (u == 0 && precision == 0)
		return ;
	if ((u / 10) > 0)
		ft_putnbr_u((u / 10), precision);
	ft_putchar((u % 10) + '0');
}

int				ft_count_u(unsigned int u, int precision)
{
	int		i;

	i = 0;
	if (u == 0 && precision != 0)
		i++;
	while (u > 0)
	{
		i++;
		u = u / 10;
	}
	return (i);
}

int				ft_print_u(t_var *info, unsigned int u)
{
	int		i;
	int		j;
	int		k;

	i = ft_count_u(u, info->pr);
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
	ft_putnbr_u(u, info->pr);
	while (j > i && (info->flag_z == 0 || info->pr == 0))
		i = ft_print_fill(i, '+', ' ');
	return (i);
}
