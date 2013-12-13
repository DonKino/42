/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:48:33 by jburet            #+#    #+#             */
/*   Updated: 2013/11/19 11:38:20 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int nbr, size_t len)
{
	unsigned char	*dst;
	size_t			i;

	dst = str;
	i = 0;
	while (i < len)
	{
		dst[i] = nbr;
		i++;
	}
	return (str);
}
