/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:06:53 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/26 16:29:53 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*strnbr;

	strnbr = ft_itoa(n);
	write(fd, strnbr, ft_strlen(strnbr));
	free(strnbr);
}
