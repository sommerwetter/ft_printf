/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:54:04 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/26 18:49:11 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static	void	format(char f, va_list *arg)
{
	char	*p;

	p = NULL;
	if (f == 'c')
		ft_putchar_fd(va_arg(*arg, int), 1);
	if (f == 's')
		ft_putstr_fd(va_arg(*arg, char *), 1);
	if (f == 'p')
	{
		p = va_arg(*arg, char *);
		ft_putstr_fd(&p[2], 1);
	}
	if (f == 'i' || f == 'd')
		ft_putnbr_fd(va_arg(*arg, int), 1);
	if (f == 'u')
		ft_put_unsigned_nbr_fd(va_arg(*arg, unsigned int), 1);
	if (f == 'x')
		ft_put_hexa_low(va_arg(*arg, unsigned int));
	if (f == 'X')
		ft_put_hexa_up(va_arg(*arg, unsigned int));
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
		if (text[i] == '%')
		{
			format(text[i + 1], &arg);
			i++;
		}
		else
			ft_putchar_fd(text[i], 1);
		i++;
	}
	va_end(arg);
	return (0);
}

int	main()
{
	char *lol = "hey";

	printf("hi\n%p\n", lol);
	ft_printf("hi\n%p\n", lol);
}