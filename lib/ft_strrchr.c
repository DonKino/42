/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:02:48 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 15:02:49 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char		*ft_strrchr(const char *str, int occ)
{
	int 	i;
	char	ch;

	i = ft_strlen(str);
	ch = occ;
	if (ch == '\0')
	{
		return ((char *)&str[i]);
	}
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	return (NULL);
}
