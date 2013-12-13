/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:01:48 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 16:37:01 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lstnew;

	while (lst != NULL)
	{
		lstnew = malloc(sizeof(t_list));
		if (!lstnew)
			return (NULL);
		lstnew = f(lst);
		lst = lst->next;
		lstnew = lstnew->next;
	}
	return (lstnew);
}
