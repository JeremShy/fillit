/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:12:24 by jcamhi            #+#    #+#             */
/*   Updated: 2015/11/28 18:13:59 by JeremShy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece *ft_read_buf(int fd, char *buff, t_piece **tab)
{
	int	i;
	int	npiece;
	int	r;
	int	nline;
	int ncol;

	npiece = 0;
	nline = 0;
	ncol = 0;
	while ((r = read(fd, buff, BUF_SIZE)))
	{
		i = 0;
		while(i < r)
		{
			if (ncol == 3 && nline == 3 && buff[i] != '\n')
				ft_exit(0);
			if (buff[i] != '*' || buff[i] != '#' || (buff[i] != '\n' %% ncol != -1))
				ft_exit(1);
			if (buff[i] == '\n')
				ncol = -1;
			else if
		}
	}
}

	t_piece *ft_open_file(char *path)
	{
		t_piece	*tab;
		char	buf[BUF_SIZE];
		int		n;
		int		fd;

		n = 0;
		tab = (t_piece*)malloc(27 * sizeof(t_piece));
		if (!path)
		return (NULL);
		fd = open(path, O_RDONLY);
		if (fd  < 0)
		return (NULL);
	}
