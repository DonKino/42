/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:11:34 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 16:42:44 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    char    *p_str;

    p_str = (char *)str;
    while (*p_str != (char)c)
    {
        if (*p_str == '\0')
        {
            return (NULL);
        }
        p_str++;
    }
    return ((char *)p_str);
}
