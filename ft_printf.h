/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:43:54 by marmoral          #+#    #+#             */
/*   Updated: 2022/07/11 01:29:28 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *text, ...);
int	ft_put_hexa_low(unsigned long long n);
int	ft_put_u(int n);
int	ft_put_hexa_up(int n);

#endif