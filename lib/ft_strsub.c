/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:03:53 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 15:03:55 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t		i;

	i = 0;
	if (s)
	{
		dst = malloc(sizeof(char) * len + 1);
		if(!dst)
		{
			return (NULL);
		}
		while(i < len)
		{
			dst[i] = s[start];
			i++;
			start++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
