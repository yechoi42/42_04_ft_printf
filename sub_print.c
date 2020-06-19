/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:58:35 by yechoi            #+#    #+#             */
/*   Updated: 2020/05/02 17:06:55 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_space(t_struct *info)
{
	int i;

	i = (ft_strchr("di", info->spec)
			&& *((long long *)(info->arg)) < 0) ? 1 : 0;
	if (info->len < info->prec)
	{
		while (i++ < (info->width - info->prec))
		{
			ft_putchar(' ');
			info->result++;
		}
	}
	else
	{
		if (info->zero == 1 && info->minus == 0
				&& info->dot == 0 && info->prec == 0)
			return ;
		while (i++ < (info->width - info->len))
		{
			ft_putchar(' ');
			info->result++;
		}
	}
}

void		print_zero(t_struct *info)
{
	int i;

	i = 0;
	if (info->len < info->prec)
	{
		while (i++ < info->prec - info->len)
		{
			ft_putchar('0');
			info->result++;
		}
	}
	else if (info->zero == 1 && info->prec == 0
			&& info->dot == 0 && info->minus == 0)
	{
		i = (ft_strchr("di", info->spec)
				&& *((long long *)(info->arg)) < 0) ? 1 : 0;
		while (i++ < info->width - info->len)
		{
			ft_putchar('0');
			info->result++;
		}
	}
}

void		cs_print_space(t_struct *info)
{
	int i;

	i = 0;
	if (info->spec == 's' && info->prec && info->prec < info->len)
	{
		while (i++ < info->width - info->prec)
		{
			ft_putchar(' ');
			info->result++;
		}
	}
	else if (!(info->zero == 1 && info->minus == 0))
	{
		while (i++ < info->width - info->len)
		{
			ft_putchar(' ');
			info->result++;
		}
	}
}

void		cs_print_zero(t_struct *info)
{
	int i;

	i = 0;
	if (info->zero == 1 && info->minus == 0)
	{
		while (i++ < info->width - info->len)
		{
			ft_putchar('0');
			info->result++;
		}
	}
}
