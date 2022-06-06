/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:06:04 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/06 10:25:16 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	digits(unsigned long n_cpy)
{
	size_t	i;

	i = 0;
	while (n_cpy > 0)
	{
		i++;
		n_cpy /= 16;
	}
	return (i);
}

static	void	transform(char *nbr, size_t i, unsigned long n_cpy)
{
	int		r;
	char	*hex;

	r = 0;
	hex = "0123456789ABCDEF";
	while (n_cpy > 0)
	{
		r = n_cpy % 16;
		nbr[i] = hex[r];
		n_cpy /= 16;
		i--;
	}
}

int	ft_put_hexa_up(int n)
{
	unsigned long	n_cpy;
	char			*nbr;
	size_t			i;
	size_t			di;

	i = 0;
	di = 0;
	if (n < 0)
	{
		n *= -1;
		n_cpy = (4294967295 + 1) - n;
	}
	else
		n_cpy = n;
	di = digits(n_cpy);
	i = di;
	nbr = malloc(i + 1);
	nbr[i--] = 0;
	transform(nbr, i, n_cpy);
	ft_putstr_fd(nbr, 1);
	free (nbr);
	return (di);
}
