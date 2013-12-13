/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:00:20 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 15:00:22 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = ft_strlen(str1);
	while (*str2 && len)
	{
		str1[i] = *str2;
		str2++;
		len--;
		i++;
	}
	str1[i] = '\0';
	return(str1);
}
