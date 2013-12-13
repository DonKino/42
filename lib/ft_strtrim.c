/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:23:59 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 14:50:20 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	char	*dst;
	size_t		j;
	size_t		k;

	if (!s)
		return (NULL);
	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	k = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	j = i;
	while (s[i] != '\0')
		i++;
	if (i > 0)
		i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
		i--;
	while (j <= i)
	{
		dst[k] = s[j];
		k++;
		j++;
	}
	dst[k] = '\0';
	return (dst);
}
