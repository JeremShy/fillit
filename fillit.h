/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:41:20 by magouin           #+#    #+#             */
/*   Updated: 2015/12/02 00:00:16 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# include <stdio.h>

typedef struct	s_piece {
	char		tab[4][4];
	char		name;
	int			*dim;
}				t_piece;

t_piece			**ft_read_buff(int fd);
void			ft_verif(t_piece const *piece);
void			print_piece(t_piece *piece);
void			print_tab(char **tab, size_t size);
void			print_list(t_piece **liste);
void			modiftab(char **tab, t_piece *piece, int x, int y);
int				ft_tablen(t_piece **tab);
#endif
