/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:01:09 by jburet            #+#    #+#             */
/*   Updated: 2013/12/13 13:18:58 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
#define _FT_LS_H
#include <libft.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

typedef		struct 		s_ft_stat
{
	char				*date;
	char				*owner_name;
	char				*group_name;
	nlink_t				nb_link;
	char				*file_name;
	off_t				file_size;
	char				*file_mode;
}						t_ft_stat;

typedef struct 		s_ls_args
{
	int		opt_l;
	int		opt_R;
	int		opt_a;
	int		opt_r;
	int		opt_t;
}					t_ls_args;

char		*format_date(char *date);

char		*format_mode(int st_mode);

char		*get_owner_name(uid_t st_uid);

char		*get_group_name(gid_t st_gid);

void		print_ls(t_ft_stat *stat, t_ls_args *args, int nb);

t_ft_stat	*get_ft_stats(struct stat *stats, char *file_name);

int			read_dir(char *dir_name, t_ls_args *args);

t_ls_args	*get_args(char **argv, int argc);

t_ls_args	*init_args(void);

int			is_arg(char *s);

int			no_args(t_ls_args *args);

void		ls_recursive(char *dir_name, t_ls_args *args);

int			is_dir(char *path);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:10:07 by jburet            #+#    #+#             */
/*   Updated: 2013/12/02 14:17:08 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*format_date(char *date)
{
	char	*ls_date;
	int		i;
	int		j;

	ls_date = malloc(sizeof(char) * 13);
	i = 0;
	j = 4;

	while (j < 16)
	{
		ls_date[i] = date[j];
		i++;
		j++;
	}
	ls_date[i] = '\0';
	return (ls_date);
}

char	*format_mode(int st_mode)
{
	char	*file_mode;

	file_mode = malloc(sizeof(char) * 11);
	if (st_mode / 10000 == 1)
		file_mode[0] = ('d');
	else
		file_mode[0] = ('-');
	file_mode[1] = ((st_mode & S_IRUSR) ? 'r' : '-');
	file_mode[2] = ((st_mode & S_IWUSR) ? 'w' : '-');
	file_mode[3] = ((st_mode & S_IXUSR) ? 'x' : '-');
	file_mode[4] = ((st_mode & S_IRGRP) ? 'r' : '-');
	file_mode[5] = ((st_mode & S_IWGRP) ? 'w' : '-');
	file_mode[6] = ((st_mode & S_IXGRP) ? 'x' : '-');
	file_mode[7] = ((st_mode & S_IROTH) ? 'r' : '-');
	file_mode[8] = ((st_mode & S_IWOTH) ? 'w' : '-');
	file_mode[9] = ((st_mode & S_IXOTH) ? 'x' : '-');
	file_mode[10] = '\0';
	return (file_mode);
}

char	*get_owner_name(uid_t st_uid)
{
	struct passwd	*infos;
	char			*owner_name;

	infos = getpwuid(st_uid);
	owner_name = infos->pw_name;
	return (owner_name);
}

char	*get_group_name(gid_t st_gid)
{
	struct group	*infos;
	char			*group_name;

	infos = getgrgid(st_gid);
	group_name = infos->gr_name;
	return (group_name);
}
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
