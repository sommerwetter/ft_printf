/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_low.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:05:53 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/26 18:30:31 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

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
	hex = "0123456789abcdef";
	while (n_cpy > 0)
	{
		r = n_cpy % 16;
		nbr[i] = hex[r];
		n_cpy /= 16;
		i--;
	}
}

void	ft_put_hexa_low(int n)
{
	unsigned long	n_cpy;
	char			*nbr;
	size_t			i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		n_cpy = (4294967295 + 1) - n;
	}
	else
		n_cpy = n;
	i = digits(n_cpy);
	nbr = malloc(i + 1);
	nbr[i--] = 0;
	transform(nbr, i, n_cpy);
	ft_putstr_fd(nbr, 1);
	free (nbr);
}
