/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:42:48 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/07 12:16:23 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	unsigned long	reversenbr(unsigned long nb)
{
	int				b;
	unsigned long	r;

	r = 0;
	b = 0;
	while (nb > 0)
	{
		b = (nb % 10);
		r = r * 10 + b;
		nb /= 10;
	}
	return (r);
}

static	void	ft_put_unsigned_nbr(unsigned long nb)
{
	int					b;
	unsigned long		a;

	a = reversenbr(nb);
	b = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
		write(1, "-", 1);
	while (a > 0)
	{
		b = (a % 10) + '0';
		write (1, &b, 1);
		a /= 10;
	}
	while ((nb % 10) == 0 && nb != 0)
	{
		write(1, "0", 1);
		nb = nb / 10;
	}
}

int	ft_put_u(int n)
{
	size_t			len;
	unsigned long	x;
	long			nc;

	len = 0;
	x = n;
	nc = n;
	if (n == 0)
		len++;
	if (n < 0)
	{
		nc *= -1;
		x = (4294967295 + 1) - nc;
		ft_put_unsigned_nbr(x);
	}
	else
		ft_put_unsigned_nbr(x);
	while (x > 0)
	{
		len++;
		x /= 10;
	}
	return (len);
}
