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
