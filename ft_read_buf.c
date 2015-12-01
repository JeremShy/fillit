/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:47:40 by magouin           #+#    #+#             */
/*   Updated: 2015/12/01 18:59:45 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_piece	*ft_create(char name)
{
	t_piece		*ret;

	ret = malloc(sizeof(t_piece));
	ret->name = name;
	return (ret);
}

static	void	init(int *i, int r, int *nline, int *ncol)
{
	*i = 0;
	if (r < 20)
		exit(EXIT_FAILURE);
	*nline = 0;
	*ncol = 0;
}

static void		ft_increment(int *ncol, int *nline, int *i, int r)
{
	*ncol = 0;
	(*nline)++;
	if (*i + 1 < r)
		*i = *i + 1;
}

static void		ft_buffer(char *buff, int r, t_piece *ret)
{
	int		i;
	int		nline;
	int		ncol;

	i = 0;
	init(&i, r, &nline, &ncol);
	while (i < r)
	{
		if (ncol < 4 && buff[i] != '.' && buff[i] != '#')
			exit(EXIT_FAILURE);
		if (ncol < 4)
		{
			ret->tab[ncol][nline] = (buff[i] == '.' ? '.' : '#');
			ncol++;
			i++;
		}
		if (ncol == 4)
		{
			if (buff[i] != '\n')
				exit(EXIT_FAILURE);
			ft_increment(&ncol, &nline, &i, r);
		}
		if (nline == 4 && ncol == 0)
			buff[i] != '\n' ? exit(EXIT_FAILURE) : (i = r);
	}
}

t_piece			**ft_read_buff(int fd)
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
		ft_buffer(buff, r, ret[i]);
		ft_verif(ret[i]);
		i++;
	}
	if ((c + 1) % 21 != 0)
		exit(EXIT_FAILURE);
	ret[i] = NULL;
	return (ret);
}
