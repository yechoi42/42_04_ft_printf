/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:50:13 by yechoi            #+#    #+#             */
/*   Updated: 2020/04/30 20:50:08 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(t_struct *info, va_list ap)
{
	int result;

	result = 0;
	if (info->spec == 'd' || info->spec == 'i' || info->spec == 'u')
		result = print_diu(info, ap);
	else if (info->spec == 'x' || info->spec == 'X')
		result = print_x(info, ap);
	else if (info->spec == 'p')
		result = print_p(info, ap);
	else if (info->spec == 'c' || info->spec == '%')
		result = print_cpct(info, ap);
	else if (info->spec == 's')
		result = print_s(info, ap);
	return (result);
}

void	init_struct(t_struct *info)
{
	info->arg = 0;
	info->result = 0;
	info->len = 0;
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->dot = 0;
	info->prec = 0;
	info->spec = 0;
}

int		parse_putchar(char c, int result)
{
	ft_putchar(c);
	result++;
	return (result);
}

int		parse_format(va_list ap, char *format)
{
	int				i;
	int				result;
	static t_struct	*info;

	i = 0;
	result = 0;
	if (!(info = (t_struct *)malloc(sizeof(t_struct) * 1)))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			result = parse_putchar(format[i++], result);
		if (format[i] == '%')
		{
			i++;
			init_struct(info);
			while (format[i] != '\0' && !(ft_strchr(SPEC, format[i])))
				check_info(ap, (char *)format, i++, info);
			info->spec = (format[i] && ft_strchr(SPEC, format[i])) ?
				format[i++] : 0;
			result += print_type(info, ap);
		}
	}
	free(info);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = parse_format(ap, (char *)format);
	va_end(ap);
	return (result);
}
