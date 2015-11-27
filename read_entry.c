/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:12:24 by jcamhi            #+#    #+#             */
/*   Updated: 2015/11/27 16:40:23 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE


t_piece *handle_buff(int r, t_piece *tab)
{


}

t_piece *ft_disp_file(char *path)
{
	t_piece	*tab;
	char	buf[BUF_SIZE];
	int		r;
	int		n;

	n = 0;
	tab = malloc(t_piece*)(27 * sizeof(t_piece));
	if (!path)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd  < 0)
		return (NULL);
	while (r = read(fd, buff, BUFF_SIZE))
	{
		buff[r] = '\0';
	}
}
