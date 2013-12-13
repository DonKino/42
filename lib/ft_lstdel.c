/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:17:52 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 13:17:36 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp_next;

	tmp = *alst;
	while(tmp != NULL)
	{
		tmp_next = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp_next;
	}
	*alst = NULL;
}
