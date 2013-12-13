/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:52:13 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 14:52:18 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int nbr, size_t len)
{
	char		*dst;
	const char	*src;

	dst = str1;
	src = str2;
	while(len--)
	{
		*dst = *src;
		if (*src == nbr)
			return (++dst);
		dst++;
		src++;
	}
	return(NULL);
}
