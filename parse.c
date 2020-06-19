/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:19:32 by yechoi            #+#    #+#             */
/*   Updated: 2020/05/02 17:07:15 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_flag(char *format, int i, t_struct *info)
{
	if (format[i] == '-')
	{
		if (!(info->minus))
			info->minus = 1;
	}
	else if (format[i] == '0' && format[i - 1] != '.'
			&& !(ft_strchr(DIGIT, format[i - 1])))
	{
		if (!(info->zero))
			info->zero = 1;
	}
}

void		check_width(va_list ap, char *format, int i, t_struct *info)
{
	int		tmp;

	if (!(info->width) && !(info->prec))
	{
		if (ft_strchr(DIGIT, format[i]) && format[i - 1] != '.')
			info->width = ft_atoi(format + i);
		else if (format[i] == '*' && format[i - 1] != '.')
		{
			tmp = va_arg(ap, int);
			info->width = (tmp > 0 ? tmp : tmp * (-1));
			if (tmp < 0)
				info->minus = 1;
		}
	}
}

void		check_prec(va_list ap, char *format, int i, t_struct *info)
{
	int tmp;

	if (format[i] == '.' && !(info->prec))
	{
		info->dot = 1;
		if (ft_strchr(DIGIT, format[i + 1]))
			info->prec = ft_atoi(format + i + 1);
		else if (ft_strchr(SPEC, format[i + 1]))
			info->prec = 0;
		else if (format[i + 1] == '*')
		{
			tmp = va_arg(ap, int);
			info->prec = tmp < 0 ? 0 : tmp;
			if (tmp != 0)
				info->dot = 0;
		}
	}
}

void		check_info(va_list ap, char *format, int i, t_struct *info)
{
	check_flag((char *)format, i, info);
	check_width(ap, (char *)format, i, info);
	check_prec(ap, (char *)format, i, info);
}

void		check_exception(t_struct *info)
{
	if (info->dot == 1 && info->prec == 0)
	{
		if (!(*(int *)(info->arg)))
			info->len = 0;
	}
}
