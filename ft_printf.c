/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 14:05:35 by migalvar      #+#    #+#                 */
/*   Updated: 2020/02/22 19:39:16 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_print_call(t_var *info, int *count, va_list ap, char *r)
{
	char	*s;

	if (info->type == 'c')
		count[1] = count[1] + ft_print_c(info, va_arg(ap, int));
	else if (info->type == '%')
		count[1] = count[1] + ft_print_percent(info, '%');
	else if (info->type == 's')
	{
		s = va_arg(ap, char *);
		if (s)
			count[1] = count[1] + ft_print_s(info, s, 0, 0);
		else
			count[1] = count[1] + ft_print_s(info, "(null)", 0, 0);
	}
	else if (info->type == 'p')
		count[1] = count[1] + ft_print_p(info, va_arg(ap, void *));
	else if (info->type == 'd' || info->type == 'i')
		count[1] = count[1] + ft_print_i(info, va_arg(ap, int));
	else if (info->type == 'x' || info->type == 'X')
		count[1] = count[1] + ft_print_x(info, va_arg(ap, unsigned int));
	else if (info->type == 'u')
		count[1] = count[1] + ft_print_u(info, va_arg(ap, unsigned int));
	else
		ft_print_invalid(count, r);
}

void		ft_info(t_var *info, char *r, int *count, va_list ap)
{
	while (r[count[0]] == '-' || r[count[0]] == '0')
	{
		if (r[count[0]] == '-')
			info->flag_m = 1;
		else if (info->flag_m != 1)
			info->flag_z = 1;
		count[0]++;
	}
	info->width = ft_simple_atoi(info->width, count, r, ap);
	if (info->width < 0)
	{
		info->width = info->width * (-1);
		info->flag_m = 1;
		info->flag_z = 0;
	}
	while (r[count[0]] == '.')
	{
		count[0]++;
		info->pr = ft_simple_atoi(0, count, r, ap);
	}
	if (info->pr < 0)
		info->pr = -1;
	while (r[count[0]] == ' ')
		count[0]++;
	info->type = r[count[0]];
}

void		ft_print_str(char *r, int *count)
{
	while (r[count[0]] && r[count[0]] != '%')
	{
		ft_putchar(r[count[0]]);
		count[0]++;
		count[1]++;
	}
	if (r[count[0]] == '%')
		count[0]++;
}

int			ft_printf(const char *s, ...)
{
	t_var			info;
	va_list			ap;
	int				count[2];

	count[0] = 0;
	count[1] = 0;
	va_start(ap, s);
	while (s[count[0]])
	{
		ft_print_str((char *)s, count);
		if (s[count[0]] != '\0' && s[count[0] - 1] == '%')
		{
			ft_populate(&info);
			ft_info(&info, (char *)s, count, ap);
			if (info.flag_m == 1)
				info.flag_z = 0;
			ft_print_call(&info, count, ap, (char *)s);
			if (s[count[0]] != '\0')
				count[0]++;
		}
	}
	va_end(ap);
	return (count[1]);
}
