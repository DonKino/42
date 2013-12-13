/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:01:09 by jburet            #+#    #+#             */
/*   Updated: 2013/12/13 13:34:39 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H
# include <libft.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <stdlib.h>

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
