/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils_one.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:02:26 by migalvar      #+#    #+#                 */
/*   Updated: 2020/02/20 19:10:36 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_print_invalid(int *count, char *r)
{
	while (r[count[0] - 1] != '%')
		count[0]--;
	ft_putchar('%');
	ft_print_str(r, count);
}

void	ft_populate(t_var *info)
{
	info->flag_z = 0;
	info->flag_m = 0;
	info->width = 0;
	info->pr = -1;
	info->type = 'l';
}

int		ft_simple_atoi(int i, int *count, char *r, va_list ap)
{
	while (r[count[0]] && ((r[count[0]] >= 48 && r[count[0]] <= 57) ||\
							r[count[0]] == '*'))
	{
		if (r[count[0]] == '*')
		{
			count[0]++;
			i = va_arg(ap, int);
			break ;
		}
		i = (i * 10) + (r[count[0]] - '0');
		count[0]++;
	}
	return (i);
}
