/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:55:49 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 14:55:55 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	while(*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return ((unsigned char)*str1 - (unsigned char)*str2);
	return (0);
}
