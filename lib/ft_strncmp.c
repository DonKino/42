/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:11:34 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 18:01:47 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t len)
{
	while(*str1 != '\0' && *str1 == *str2 && len--)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2 && len > 0)
		return ((unsigned char)*str1 - (unsigned char)*str2);
	return (0);
}
