/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:43:54 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/26 18:26:41 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

void	ft_put_unsigned_nbr_fd(int n, int fd);
void	ft_put_hexa_low(int n);
void	ft_put_hexa_up(int n);

#endif