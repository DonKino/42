/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:18:36 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 12:12:25 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst_new;

	lst_new = malloc(sizeof(t_list));
	if (!lst_new)
			return (NULL);
	lst_new->content = malloc(content_size);
	if (!lst_new->content)
		return(NULL);
	if(content != NULL)
	{
		lst_new->content = ft_memcpy(lst_new->content, content, content_size);
		lst_new->content_size = content_size;
	}
	else
	{
		lst_new->content = NULL;
		lst_new->content_size = 0;
	}
	lst_new->next = NULL;
	return (lst_new);
}
