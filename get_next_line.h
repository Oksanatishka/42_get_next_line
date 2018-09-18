#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# define BUFF_SIZE 32 //Macro to choose the size of the reading buffer for read function
# define FDS 65535

int		get_next_line(const int fd, char **line);

#endif