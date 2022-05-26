/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:38:10 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/07 12:50:24 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;

	if (!s1)
		return (NULL);
	s1_cpy = malloc(ft_strlen(s1) + 1);
	if (!s1_cpy)
		return (NULL);
	ft_memcpy(s1_cpy, s1, ft_strlen(s1) + 1);
	return (s1_cpy);
}
