/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:47:40 by magouin           #+#    #+#             */
/*   Updated: 2015/11/30 19:37:38 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*ft_create(char name)
{
	t_piece		*ret;

	ret = malloc(sizeof(t_piece));
	ret->name = name;
	return (ret);
}

void	ft_buffer(char *buff, int r, t_piece *ret)
{
	int		i;
	int		nline;
	int		ncol;

	i = 0;
	if (r < 20)
		exit(EXIT_FAILURE);
	nline = 0;
	ncol = 0;
	while (i < r)
	{
//		printf("ncol : %d - nline : %d - r : %d - i : %d\n", ncol, nline, r, i);
		if (ncol < 4 && buff[i] != '.' && buff[i] != '#')
			exit(EXIT_FAILURE);
		if (ncol < 4)
		{
			if (buff[i] == '.')
				ret->tab[ncol][nline] = 0;
			else
				ret->tab[ncol][nline] = 1;
			ncol++;
			i++;
		}
		if (ncol == 4)
		{
			if (buff[i] != '\n')
				exit(EXIT_FAILURE);
			ncol = 0;
			nline++;
			i++;
		}
		if (nline == 4 && ncol == 0)
		{
			if (buff[i] != '\n')
				exit(EXIT_FAILURE);
			else
				i = r;
		}
	}
	ft_putendl("Fichier valide");
}

t_piece	**ft_read_buff(int fd)
{
	int		r;
	char	buff[BUFF_SIZE + 1];
	int		i;
	t_piece	**ret;
	int		c;

	i = 0;
	if (!(ret = malloc(27 * sizeof(t_piece*))))
		exit(EXIT_FAILURE);
	c = 0;
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		c += r;
		buff[BUFF_SIZE] = '\0';
		ret[i] = ft_create('A' + i);
		printf("La piece avec le nom %c a ete correctement creee\n", 'A' + i);
		ft_buffer(buff, r, ret[i]);
		i++;
	}
	if ((c + 1) % 21 != 0)
		exit(EXIT_FAILURE);
	return (ret);
}

void sortie(void)
{
	ft_putendl("Le fichier fut quitte (RIP)");
}

int		main(int ac, char **av)
{
	int	fd;
	t_piece **tab;

	atexit(sortie);
	if (ac == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	tab = ft_read_buff(fd);
	printf("(Ignorez le message suivant.MDR)\n");
	return (0);
}
