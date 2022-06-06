/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:54:04 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/06 10:46:24 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	format(char f, va_list *arg)
{
	if (f == 'c')
		return (ft_put_c(va_arg(*arg, int)));
	if (f == 's')
		return (ft_put_s(va_arg(*arg, char *)));
	if (f == 'p')
	{
		write(1, "0x1", 3);
		return (3 + ft_put_hexa_low(va_arg(*arg, unsigned int)));
	}
	if (f == 'i' || f == 'd')
		return (ft_put_id(va_arg(*arg, int)));
	if (f == 'u')
		return (ft_put_unsigned_nbr_fd(va_arg(*arg, unsigned int), 1));
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
	int		tmp;

	va_start(arg, text);
	i = 0;
	count = 0;
	tmp = 0;
	while (text[i])
	{
		if (text[i] == '%')
		{
			tmp = format(text[i + 1], &arg);
			count += tmp;
			i++;
		}
		else
			ft_putchar_fd(text[i], 1);
			count++;
		i++;
	}
	va_end(arg);
	return (count - 1);
}