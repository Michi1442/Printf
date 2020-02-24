/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 18:44:25 by migalvar      #+#    #+#                 */
/*   Updated: 2020/02/22 18:35:16 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_var
{
	int				flag_z;
	int				flag_m;
	int				width;
	int				pr;
	char			type;
}					t_var;

void				ft_putchar(char c);
int					ft_strlen(char *s);
void				ft_print_invalid(int *count, char *r);
void				ft_populate(t_var *info);
int					ft_simple_atoi(int i, int *count, char *r, va_list ap);

void				ft_putnbr(int n, int precision);
int					ft_print_fill(int i, char direction, char fill);
int					ft_i_len(int w, int p, int c);
int					ft_count_n(int n, int precision);
int					ft_count_x(unsigned long x, int precision);

void				ft_putstr(char *s);
int					ft_bigger_s(int width, int len, int precision);
char				*ft_hd_str(char type);
void				ft_putnbr_x(unsigned long n, char type, int precision);

int					ft_print_c(t_var *info, int c);
int					ft_print_s(t_var *info, char *s, int i, int k);
int					ft_print_p(t_var *info, void *p);
int					ft_print_i(t_var *info, int i);
int					ft_print_x(t_var *info, unsigned int n);

int					ft_print_percent(t_var *info, char c);
void				ft_putnbr_u(unsigned int u, int precision);
int					ft_count_u(unsigned int u, int precision);
int					ft_print_u(t_var *info, unsigned int u);

void				ft_info(t_var *info, char *r, int *count, va_list ap);
void				ft_print_str(char *r, int *count);
void				ft_print_call(t_var *info, int *count, va_list ap, char *r);
int					ft_printf(const char *s, ...);

#endif
