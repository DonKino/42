/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:53:07 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 14:53:10 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *s1, void const *s2, size_t n)
{
	char	*dst;
	size_t	i;
	char	*str;

	str = (char *)s2;
	dst = (char *)s1;
	i = 0;
	while(i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return(s1);
}
