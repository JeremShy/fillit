/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:25:48 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/02 00:02:37 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i);
}

void	ft_erase(char **tab, t_piece *piece)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == piece->name)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

char	**ft_backtrack(char **tab, t_piece **piece, int npiece, int *dim)
{
	static int	size = -1;

	if (size == -1)
		size = ft_sqrt(ft_tablen(piece) * 2);

	if ((piece[npiece]->dim = ft_resolve(piece[npiece], size, tab, dim)) && npiece < ft_tablen(piece))
		ft_backtrack(tab, piece, npiece + 1, diminit);
	else
	{
		ft_erase(tab, piece[npiece]);
		
		ft_backtrack(tab, piece, npiece - 1, int *dim)
	}
}
