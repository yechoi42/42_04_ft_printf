/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:55:24 by yechoi            #+#    #+#             */
/*   Updated: 2020/05/02 15:48:46 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_get_info_len(t_struct *info)
{
	int				i;
	unsigned int	arg;
	unsigned int	temp;

	i = 0;
	arg = *((unsigned int *)(info->arg));
	temp = arg;
	while (temp >= 1)
	{
		temp = temp / 16;
		i++;
	}
	info->len = (arg == 0 ? 1 : i);
}

void	p_get_info_len(t_struct *info)
{
	int				i;
	unsigned long	arg;
	unsigned long	temp;

	i = 0;
	arg = *((unsigned long *)(info->arg));
	temp = arg;
	while (temp >= 1)
	{
		temp = temp / 16;
		i++;
	}
	info->len = (arg == 0 ? 1 : i);
	info->width -= 2;
}

int		print_x(t_struct *info, va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	info->arg = &num;
	x_get_info_len(info);
	check_exception(info);
	if (info->minus == 0)
		print_space(info);
	print_zero(info);
	ft_putnbr_base(num, info);
	if (info->minus == 1)
		print_space(info);
	return (info->result);
}

int		print_p(t_struct *info, va_list ap)
{
	unsigned long	num;

	num = va_arg(ap, unsigned long);
	info->arg = &num;
	p_get_info_len(info);
	check_exception(info);
	if (info->minus == 0)
		print_space(info);
	ft_putstr("0x", info);
	print_zero(info);
	ft_putnbr_base(num, info);
	if (info->minus == 1)
		print_space(info);
	return (info->result);
}
