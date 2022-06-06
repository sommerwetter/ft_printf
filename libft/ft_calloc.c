/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:22:00 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/31 14:13:31 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	s;

	s = count * size;
	p = malloc(s);
	if (!p)
		return (NULL);
	ft_bzero(p, s);
	return (p);
}
