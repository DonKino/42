/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:03:18 by jburet            #+#    #+#             */
/*   Updated: 2013/11/20 15:03:20 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *str, const char *target)
{
  char  *p1;
  char  *p2;
  char  *p1Adv;
  char  *p1Begin;

  p1 = (char *)str;
  p2 = (char *)target;
  p1Adv = (char *)str;
  if (!*target)
    return ((char *)str);
  while (*++p2)
    p1Adv++;
  while (*p1Adv)
  {
    p1Begin = p1;
    p2 = (char *)target;
    while (*p1 && *p2 &&*p1 == *p2 && p1++)
      p2++;
    if (!*p2)
      return (p1Begin);
    p1 = p1Begin + 1;
    p1Adv++;
  }
  return (NULL);
}
