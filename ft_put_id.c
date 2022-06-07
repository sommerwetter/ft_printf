/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:17:37 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/07 09:04:12 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_id(int x)
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
