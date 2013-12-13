/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:52:39 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 14:52:43 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *)s1;
	i = 0;
	while (n--)
	{
        if (str[i] == (unsigned char)c)
        {
        	return ((void *)&str[i]);
        }  
        i++;
	}
	return (NULL);
}
