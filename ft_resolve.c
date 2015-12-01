/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:13:49 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/01 23:59:45 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creationtab(void)
{
	char **tab;
	int x;
	int y;

	x = 0;
	y = 0;
	tab = (char**)malloc(sizeof(char*) * 21);
	while (x < 20)
	{
		tab[x] = malloc(21);
		tab[x][20] = '\0';
		x++;
	}
	tab[20] = NULL;
	while (y < 20)
	{
		x = 0;
		while (x < 20)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return(tab);
}

int		ft_validite_join(char **tab, int x, int y, t_piece *piece)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece->tab[i][j] == '#' && ft_isalpha(tab[i + y][x + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_validite_size(t_piece *piece, int x, int y, int size)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece->tab[i][j] == '#' && ((x + j) >= size 
						|| (x + j) < 0 || (y + i) >= size || (y + i) < 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		*ft_resolve(t_piece *piece, int size, char **tab, int *dim)
{
	int x;
	int y;

	y = dim[1];
	x = dim[0];
	while (y < size)
	{
		if (x == size)
			x = -3;
		while (x < size)
		{
			if (ft_validite_size(piece, x, y, size))
			{
				printf("size valid.\n");
				if (ft_validite_join(tab, x, y,piece))
				{
					printf("join valid.\n");
					modiftab(tab, piece, x, y);
					dim[1] = y;
					dim[0] = x;
					return (dim);
				}
			}
			x++;
		}
		y++;
	}
	return (NULL);
}
/*
int main(int ac, char **av)
{
	int         fd;
	t_piece     **tab;

	if (ac == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	tab = ft_read_buff(fd);
	int i;
	int	j = 0;
	int x;
	int y;
	x = 0;
	y = 0;
	
	   while (j < 4)
	   {
	   i = 0;
	   while (i < 4)
	   {
	   if (tab[0]->tab[j][i] == '#')
	   tab[0]->tab[j][i] = 'A';
	   i++;
	   }
	   j++;
	   }
	char **tabl;
	tabl = creationtab();
	while (tabl[y] != NULL)
	{
		x = 0;
		while (tabl[y][x] != '\0')
		{
			tabl[y][x] = '.';
			x++;
		}
		y++;
	}
	int dim[2];
	dim[0] = 1;
	dim[1] = 1;
	tabl[0][2] = 'A';
	tabl[0][3] = 'A';
	tabl[0][4] = 'A';
	tabl[1][2] = 'A';
	tabl[1][4] = 'A';
	tabl[2][5] = 'A';
	tabl[3][1] = 'A';
	tabl[4][0] = 'A';
	tabl[4][2] = 'A';
	tabl[4][3] = 'A';
	tabl[4][4] = 'A';
	tabl[4][5] = 'A';
	tabl[5][0] = 'A';

	print_list(tab);
	ft_putchar('\n');
	print_tab(tabl, 6);
	ft_putchar('\n');
//	ft_putnbr(ft_resolve(tab[3], 6, tabl, dim));
//	ft_putchar('\n');
//	print_tab(tabl, 6);
	printf("size valide ? %d\n join valide ? %d\n", ft_validite_size(tab[3], 1, 1, 6), ft_validite_join(tabl, 1, 1, tab[3]));
	return (0);
	}*/
