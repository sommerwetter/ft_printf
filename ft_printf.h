/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:43:54 by marmoral          #+#    #+#             */
/*   Updated: 2022/06/06 10:27:59 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *text, ...);
int	ft_put_c(char c);
int	ft_put_s(char *s);
int	ft_put_id(int x);
int	ft_put_hexa_low(int n);
int	ft_put_unsigned_nbr_fd(int n, int fd);
int	ft_put_hexa_up(int n);

#endif