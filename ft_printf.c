/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:54:04 by marmoral          #+#    #+#             */
/*   Updated: 2022/07/11 01:30:33 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_put_id(int x)
{
	size_t	len;
	long	xc;

	len = 0;
	xc = x;
	ft_putnbr_fd(x, 1);
	if (xc <= 0)
	{
		xc *= (-1);
		len++;
	}
	while (xc > 0)
	{
		len++;
		xc /= 10;
	}
	return (len);
}

static	int	ft_put_s(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

static	int	ft_put_c(char c)
{
	write(1, &c, 1);
	return (1);
}

static	int	format(char f, va_list *arg)
{
	if (f == 'c')
		return (ft_put_c(va_arg(*arg, int)));
	if (f == 's')
		return (ft_put_s(va_arg(*arg, char *)));
	if (f == 'p')
	{
		write(1, "0x", 2);
		return (2 + ft_put_hexa_low(va_arg(*arg, unsigned long long)));
	}
	if (f == 'i' || f == 'd')
		return (ft_put_id(va_arg(*arg, int)));
	if (f == 'u')
		return (ft_put_u(va_arg(*arg, unsigned int)));
	if (f == 'x')
		return (ft_put_hexa_low(va_arg(*arg, unsigned int)));
	if (f == 'X')
		return (ft_put_hexa_up(va_arg(*arg, unsigned int)));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	va_list	arg;
	size_t	i;
	size_t	count;

	va_start(arg, text);
	i = 0;
	count = 0;
	while (text[i])
	{
		if (text[i] == '%' && text[i + 1] == '%')
			count += ft_put_c(text[i++]);
		else if (text[i] == '%')
			count += format(text[i++ + 1], &arg);
		else
			count += ft_put_c(text[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
