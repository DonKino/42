/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:58:36 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 14:58:38 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char	*dst;

	i = 0;
	if(s1 && s2)
	{
		dst = malloc(sizeof(char) * (ft_strlen((char *) s1) + ft_strlen((char *) s2)) + 1);
		if(!dst)
			return (NULL);
		while (i < ft_strlen((char *) s1))
		{
			dst[i] = s1[i];
			i++;
		}
		j = 0;
		while (j < ft_strlen((char *) s2))
		{
			dst[i] = s2[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
