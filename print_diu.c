/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:11:50 by yechoi            #+#    #+#             */
/*   Updated: 2020/05/02 15:00:07 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		diu_get_info_len(t_struct *info)
{
	int					i;
	long long			arg;
	unsigned long long	temp;

	i = 0;
	arg = *((long long *)(info->arg));
	temp = (arg < 0 ? arg * (-1) : arg);
	while (temp >= 1)
	{
		temp = temp / 10;
		i++;
	}
	info->len = (arg == 0 ? 1 : i);
}

int			print_diu(t_struct *info, va_list ap)
{
	long long	num;

	if (info->spec == 'd' || info->spec == 'i')
		num = va_arg(ap, int);
	else if (info->spec == 'u')
		num = va_arg(ap, unsigned int);
	info->arg = &num;
	diu_get_info_len(info);
	check_exception(info);
	if (info->minus == 0)
		print_space(info);
	if (num < 0)
	{
		ft_putchar('-');
		info->result++;
	}
	print_zero(info);
	ft_putnbr_base(num, info);
	if (info->minus == 1)
		print_space(info);
	return (info->result);
}
