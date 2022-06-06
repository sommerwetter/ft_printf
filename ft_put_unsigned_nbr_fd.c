/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:42:48 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/06 10:27:23 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	unsigned long	reverse(unsigned long n_cpy)
{
	unsigned long	n_r;
	int				nbr;

	n_r = 0;
	nbr = 0;
	while (n_cpy > 0)
	{
		nbr = n_cpy % 10;
		n_r = (n_r * 10) + nbr;
		n_cpy /= 10;
	}
	return (n_r);
}

static	void	strnbr(unsigned long n, unsigned long n_r, char *str)
{
	size_t	i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n_r > 0)
	{
		str[i] = (n_r % 10) + '0';
		n_r /= 10;
		i++;
	}
	while ((n % 10 == 0) && n != 0)
	{
		str[i] = '0';
		i++;
		n /= 10;
	}
	str[i] = 0;
}

static char	*ft_itoa_unsigned(unsigned long n)
{
	int					count;
	unsigned long		n_r;
	unsigned long		n_cpy;
	char				*str;

	count = 0;
	n_cpy = n;
	n_r = reverse(n_cpy);
	while (n_cpy > 0)
	{
		n_cpy /= 10;
		count++;
	}
	if (n == 0)
		count++;
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	strnbr(n, n_r, str);
	return (str);
}

int	ft_put_unsigned_nbr_fd(int n, int fd)
{
	char	*strnbr;
	size_t	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		strnbr = ft_itoa_unsigned((4294967295 + 1) - n);
	}
	else
		strnbr = ft_itoa_unsigned(n);
	size = ft_strlen(strnbr);
	write(fd, strnbr, size);
	free(strnbr);
	return (size);
}
