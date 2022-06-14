/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_low.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:05:53 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/14 16:32:30 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	digits(unsigned long long n_cpy)
{
	size_t	i;

	i = 0;
	if (n_cpy == 0)
		return (1);
	while (n_cpy > 0)
	{
		i++;
		n_cpy /= 16;
	}
	return (i);
}

static	void	transform(char *nbr, size_t i, unsigned long long n_cpy)
{
	int		r;
	char	*hex;

	r = 0;
	hex = "0123456789abcdef";
	if (n_cpy == 0)
		nbr[i] = hex[r];
	while (n_cpy > 0)
	{
		r = n_cpy % 16;
		nbr[i] = hex[r];
		n_cpy /= 16;
		i--;
	}
}

int	ft_put_hexa_low(unsigned long long n)
{
	unsigned long long	n_cpy;
	char				*nbr;
	unsigned long long	nc;
	size_t			i;
	size_t			di;

	i = 0;
	di = 0;
	nc = n;
	if (n < 0)
	{
		nc *= -1;
		n_cpy = (4294967295 + 1) - nc;
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
