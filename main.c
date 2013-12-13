/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:01:09 by jburet            #+#    #+#             */
/*   Updated: 2013/12/13 12:54:29 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_ls_args			*args;
	int					i;
	int					read;

	i = 1;
	args = get_args(argv, argc);
	while (is_arg(argv[i]) == 0 && argv[i])
		i++;
	if (i == argc)
		read = read_dir(".", args);
	while (i < argc)
	{
		read = read_dir(argv[i], args);
		i++;
	}
	return (0);
}
