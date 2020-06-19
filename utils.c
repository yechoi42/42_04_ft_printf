/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:07:13 by yechoi            #+#    #+#             */
/*   Updated: 2020/05/02 17:08:55 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

int		ft_atoi(const char *nptr)
{
	int	sign;
	int value;

	sign = 1;
	value = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		value = value * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * value);
}

void	ft_putnbr_base(long long nb, t_struct *info)
{
	long long	nb2;
	long long	base;
	char		*base_arr;

	nb2 = nb;
	if (nb2 == 0 && !(info->dot == 1 && info->prec == 0))
	{
		ft_putchar('0');
		info->result++;
		return ;
	}
	nb = nb < 0 ? nb * (-1) : nb;
	base = ft_strchr(DECIMAL, info->spec) ? 10 : 16;
	base_arr = ft_strchr(DECIMAL, info->spec) ? DIGIT : HEXA_S;
	if (info->spec == 'X')
		base_arr = HEXA_C;
	if (nb > 0)
	{
		if (nb >= base)
			ft_putnbr_base(nb / base, info);
		ft_putchar(base_arr[nb % base]);
		info->result++;
	}
}

void	ft_putstr(char *str, t_struct *info)
{
	int i;

	i = 0;
	if (info->spec == 's' && info->prec)
	{
		while (i < info->prec && str[i])
		{
			ft_putchar(str[i++]);
			info->result++;
		}
	}
	else if (info->spec == 's' && info->prec == 0 && info->dot == 1)
		return ;
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i++]);
			info->result++;
		}
	}
}
