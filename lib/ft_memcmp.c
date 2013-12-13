/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:52:53 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 14:52:57 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned char	s1;
	unsigned char	s2;

	while(len--)
	{
		s1 = *(unsigned char *)str1++;
		s2 = *(unsigned char *)str2++;
		if (s1 != s2)
			return (s1 - s2);
	}
	return (0);
}
