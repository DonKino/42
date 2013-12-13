/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:01:02 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 15:01:04 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncpy(char *str1, const char *str2, int len)
{
	char	*dst;
	int		i;
	
	i = 0;
	dst = str1;
	while(i < len)
	{
		if (str2[i] == '\0')
		{
			while(i < len)
			{
				dst[i] = '\0';
				i++;
			}
			return (str1);
		}
		else
		{
			dst[i] = str2[i];
			i++;
		}
	}
	return(str1);	
}
