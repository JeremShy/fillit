#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1000
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>

void ft_exit(void);
typedef struct s_piece
{
  char  name;
  int   tab[4][4];

} t_piece;

# endif
