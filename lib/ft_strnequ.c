/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:01:30 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 15:01:32 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 && s2)
	{
		while(s1[i] != '\0' && s2[i] != '\0' && i < n )
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if ((s1[i] == s2[i]) || n == i )
			return (1);
		return (0);
	}
	return (0);
}
