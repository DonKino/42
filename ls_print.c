/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:18:52 by jburet            #+#    #+#             */
/*   Updated: 2013/12/13 13:17:10 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_stats(t_ft_stat *stat)
{
	ft_putstr("\n");
	ft_putstr(stat->file_mode);
	ft_putstr("\t");
	ft_putnbr(stat->nb_link);
	ft_putstr("\t");
	ft_putstr(stat->owner_name);
	ft_putstr("\t");
	ft_putstr(stat->group_name);
	ft_putstr("\t");
	ft_putnbr((int)stat->file_size);
	ft_putstr("\t");
	ft_putstr(stat->date);
	ft_putstr("\t");
	ft_putstr(stat->file_name);
}


void	print_ls(t_ft_stat *stat, t_ls_args *args, int nb)
{
	if (args->opt_a == 0 && stat->file_name[0] != '.' && args->opt_l == 0)
	{
		ft_putstr(stat->file_name);
		if (nb % 3 == 0)
			ft_putstr("\n");
		else
			ft_putstr("\t\t");
	}
	else if (args->opt_a == 1 && args->opt_l == 0)
	{
		ft_putstr(stat->file_name);
		if (nb % 3 == 0)
			ft_putstr("\n");
		else
			ft_putstr("\t\t");
	}
	else if (args->opt_l == 1 && args->opt_a == 1)
		print_stats(stat);
	else if (args->opt_l == 1 && args->opt_a == 0 && stat->file_name[0] != '.')
		print_stats(stat);
}

t_ft_stat	*get_ft_stats(struct stat *stats, char *file_name)
{
	struct timespec		modif_time;
	time_t				modif_sec;
	t_ft_stat			*ft_stats;

	ft_stats = malloc(sizeof(t_ft_stat));
	modif_time = stats->st_mtimespec;
	modif_sec = modif_time.tv_sec;
	ft_stats->date = format_date(ctime(&modif_sec));
	ft_stats->file_mode = format_mode((int)stats->st_mode);
	ft_stats->nb_link = (int)stats->st_nlink;
	ft_stats->owner_name = get_owner_name(stats->st_uid);
	ft_stats->group_name = get_group_name(stats->st_gid);
	ft_stats->file_size = (int)stats->st_size;
	ft_stats->file_name = file_name;
	return (ft_stats);
}

char	*get_path(char *dir_name, char *d_name)
{
	char		*path;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	path = malloc(sizeof(char) * (ft_strlen(dir_name) + ft_strlen(d_name) + 2));
	while (i < ft_strlen(dir_name))
	{
		path[i] = dir_name[i];
		i++;
	}
	path[i++] = '/';
	while (j < ft_strlen(d_name))
		path[i++] = d_name[j++];
	path[i] = '\0';
	return (path);
}

int		read_dir(char *dir_name, t_ls_args *args)
{
	DIR				*open;
	struct dirent	*read;
	struct stat		stats;
	char			*path;
	int				i;

	i = 0;
	if ((open = opendir(dir_name)) > 0)
	{
		while ((read = readdir(open)) != NULL)
		{
			path = get_path(dir_name, read->d_name);
			if (stat(path, &stats) == 0)
				print_ls(get_ft_stats(&stats, (char *)read->d_name), args, i++);
			else
				ft_putstr(strerror(errno));
		}
		ft_putchar('\n');
		closedir(open);
		return (0);
	}
	ft_putstr("ft_ls: ");
	ft_putstr(dir_name);
	ft_putstr(": No such File or directory\n");
	return (1);
}
