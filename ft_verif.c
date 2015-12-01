/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:57:10 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/01 17:54:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	test(t_piece const *piece, int x, int y, int *connection)
{
	if (piece->tab[y + 1][x] == '#')
		(*connection)++;
	if (piece->tab[y][x + 1] == '#')
		(*connection)++;
}

void		ft_verif(t_piece const *piece)
{
	int diese;
	int x;
	int y;
	int connection;

	y = 0;
	diese = 0;
	connection = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (piece->tab[y][x] == '#')
			{
				test(piece, x, y, &connection);
				diese++;
			}
			x++;
		}
		y++;
	}
	if (connection < 3 || diese != 4)
		exit(EXIT_FAILURE);
}
