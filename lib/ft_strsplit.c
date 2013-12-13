/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:11:34 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 15:36:10 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_str(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while(s[i] == c && s[i] != '\0')
		i++;
	while(s[i] != '\0')
	{
		if (s[i++] == c)
		{
			count++;
			while(s[i] == c)
				i++;
		}
	}
	if (s[i - 1] == c && count > 0)
		return (count - 1);
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	l = 0;
	if(!s || !c)
		return (NULL);
	dst = ft_memalloc(ft_count_str(s, c));
	while(l <= ft_count_str(s, c))
	{
		k = 0;
		while(s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while(s[j] != c && s[j] != '\0')
			j++;
		dst[l] = ft_memalloc(sizeof(char) * (j - i));
		while(i < j && s[i] != '\0')
			dst[l][k++] = s[i++];
		dst[l][k] = '\0';
		l++;
	}
	dst[l] = NULL;
	return(dst);
}
