/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:25:20 by yechoi            #+#    #+#             */
/*   Updated: 2020/05/02 17:26:29 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_strlen(char *str, t_struct *info)
{
	int i;

	if (info->dot == 1 && info->prec == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		print_cpct(t_struct *info, va_list ap)
{
	int c;

	c = (info->spec == 'c' ? va_arg(ap, int) : '%');
	info->arg = &c;
	info->len = 1;
	if (info->minus == 0)
		cs_print_space(info);
	cs_print_zero(info);
	ft_putchar(c);
	info->result++;
	if (info->minus == 1)
		cs_print_space(info);
	return (info->result);
}

int		print_s(t_struct *info, va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	str = (str == NULL ? "(null)" : str);
	info->arg = str;
	info->len = s_strlen(str, info);
	if (info->minus == 0)
		cs_print_space(info);
	cs_print_zero(info);
	ft_putstr(str, info);
	if (info->minus == 1)
		cs_print_space(info);
	return (info->result);
}
