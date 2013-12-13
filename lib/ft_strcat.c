/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:54:58 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 14:55:00 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strcat(char *str1, char *str2)
{
	size_t		len;
	char		*dst;
	size_t		i;
	size_t		j;

	j = 0;
	i = ft_strlen(str1);
	len = ft_strlen(str1) + ft_strlen(str2);
	dst = str1;
	while(i < len)
	{
		dst[i] = str2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return(str1);
}
