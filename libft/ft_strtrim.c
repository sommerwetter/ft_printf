/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:53:49 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/22 19:46:23 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	x;
	int		end;
	char	*s1_trim;

	i = 0;
	x = 0;
	end = ft_strlen(s1);
	while (set[x])
	{
		if (s1[i] == set[x])
		{
			i++;
			x = -1;
		}
		else if (s1[end - 1] == set[x] && end > i)
		{
			end--;
			x = -1;
		}
		x++;
	}
	s1_trim = ft_substr(s1, i, (end - i));
	return (s1_trim);
}
