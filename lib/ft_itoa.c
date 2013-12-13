/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:11:34 by jburet            #+#    #+#             */
/*   Updated: 2013/11/28 15:58:39 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_to_char(int n, char *dst, int mult, int sign, int bullshit)
{
	int		tmp;
	int		size;

	size = sign - 1;
	if (sign == 2)
		dst[0] = '-';
	while(mult >= 1)
	{
		tmp = n;
		dst[size] =(tmp / mult) + '0';
		size++;
		n %= mult;
		mult /= 10;
	}
	if (bullshit == 1)
		dst[size - 1] = '8';
	dst[size] = '\0';
}
#include <stdio.h>
char	*ft_itoa(int n)
{
	char		*dst;
	int			mult;
	int			size;
	int			sign;
	int			bullshit;

	mult = 1;
	size = 1;
	sign = 1;
	bullshit = 0;
	if (n == -2147483648)
	{
		n = n + 1;
		bullshit = 1;
	}
	if (n < 0)
	{
		n *= -1;
		sign = 2;
	}
	while(n / mult >= 10 && size++)
		mult *= 10;
	dst = malloc(sizeof(char) * size + sign);
	if (!dst)
		return (NULL);
	int_to_char(n, dst, mult, sign, bullshit);
	return(dst);
}
