/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:12:24 by jcamhi            #+#    #+#             */
/*   Updated: 2015/11/28 17:12:43 by JeremShy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece *ft_read_buf(int fd, char *buff, t_piece **tab)
{
	int	i;
	int	npiece;
	int	r;
	int	ntab;

	npiece = 0;
	ntab = 0;
	while ((r = read(fd, buff, BUF_SIZE)))
	{
		i = 0;
		while(i < r)
		{
			if (buff[i] == '\n' && ntab == 15)
			npiece++;
			else
			{
				if (ntab / 4 == 4 || ntab % 4 == 4 ||
					(buff[i] != '.' && buff[i] != '#')
					ft_exit();
					if (ntab / 4 == 0 && ntab % 4 == 0)
					tab[npiece]->name = 'A' + npiece;

				}
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
