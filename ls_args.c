/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:36:17 by jburet            #+#    #+#             */
/*   Updated: 2013/12/13 12:55:18 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_arg(char *s)
{
	if (!s)
		return (1);
	if (s[0] == '-')
		return (0);
	return (1);
}


t_ls_args	*init_args(void)
{
	t_ls_args	*args;

	if (!(args = malloc(sizeof(t_ls_args))))
		exit(-1);
	args->opt_l = 0;
	args->opt_R = 0;
	args->opt_a = 0;
	args->opt_r = 0;
	args->opt_t = 0;
	return (args);
}

t_ls_args	*attrib_args(t_ls_args *args, char c)
{
	if (c == 'l')
		args->opt_l = 1;
	if (c == 'R')
		args->opt_R = 1;
	if (c == 'a')
		args->opt_a = 1;
	if (c == 'r')
		args->opt_r = 1;
	if (c == 't')
		args->opt_t = 1;
	return (args);
}

t_ls_args	*get_args(char **argv, int argc)
{
	t_ls_args	*args;
	int			i;
	int			j;
	int			still_args;

	still_args = 0;
	i = 1;
	args = init_args();
	while (i < argc && still_args == 0)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			while (argv[i][j])
				args = attrib_args(args, argv[i][j++]);
		}
		else
			still_args = 1;
		i++;
	}
	return (args);
}

int		no_args(t_ls_args *args)
{
	if (args->opt_l == 1)
		return (1);
	if (args->opt_R == 1)
		return (1);
	if (args->opt_a == 1)
		return (1);
	if (args->opt_r == 1)
		return (1);
	if (args->opt_t == 1)
		return (1);
	return (0);
}
