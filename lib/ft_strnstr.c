/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:02:26 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 15:02:28 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t slen)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (*find == '\0')
		return ((char *)str);
	while(str[i] != '\0' && i < slen)
	{
		j = 0;
		if (str[i] == find[0])
		{
			k = i;
			while (str[k] == find[j] && k < slen)
			{
				k++;
				j++;
			}
			if (--k == slen || find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
