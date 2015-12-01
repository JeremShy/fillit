/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:41:20 by magouin           #+#    #+#             */
/*   Updated: 2015/12/01 16:48:32 by jcamhi           ###   ########.fr       */
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
	int			tab[4][4];
	char		name;
}				t_piece;

t_piece			**ft_read_buff(int fd);
void			ft_verif(t_piece const *piece);
#endif
