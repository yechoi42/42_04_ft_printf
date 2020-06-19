/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:59:07 by yechoi            #+#    #+#             */
/*   Updated: 2020/05/02 15:03:30 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPEC "diuxXpcs%"
# define DECIMAL "diu"
# define DIGIT "0123456789"
# define HEXA_C "0123456789ABCDEF"
# define HEXA_S "0123456789abcdef"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_struct
{
	void		*arg;
	int			result;
	int			len;
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			prec;
	char		spec;
}				t_struct;

/*
** ft_printf.c
*/

int				print_type(t_struct *info, va_list ap);
void			init_struct(t_struct *info);
int				parse_format(va_list ap, char *format);
int				parse_putchar(char c, int result);
int				ft_printf(const char *format, ...);

/*
** parse.c
*/

void			check_flag(char *format, int i, t_struct *info);
void			check_width(va_list ap, char *format, int i, t_struct *info);
void			check_prec(va_list ap, char *format, int i, t_struct *info);
void			check_info(va_list ap, char *format, int i, t_struct *info);
void			check_exception(t_struct *info);

/*
** sub_print.c
*/

void			print_space(t_struct *info);
void			print_zero(t_struct *info);
void			cs_print_space(t_struct *info);
void			cs_print_zero(t_struct *info);

/*
** utils.c
*/

void			ft_putchar(char c);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *nptr);
void			ft_putnbr_base(long long nb, t_struct *info);
void			ft_putstr(char *str, t_struct *info);

/*
** print_diu.c
*/

void			diu_get_info_len(t_struct *info);
int				print_diu(t_struct *info, va_list ap);

/*
** print_xp.c
*/

void			x_get_info_len(t_struct *info);
void			p_get_info_len(t_struct *info);
int				print_x(t_struct *info, va_list ap);
int				print_p(t_struct *info, va_list ap);

/*
** print_cspct.c
*/

int				s_strlen(char *str, t_struct *info);
int				print_cpct(t_struct *info, va_list ap);
int				print_s(t_struct *info, va_list ap);

#endif
