#include "get_next_line.h"

// strchr -- locate character in string
// strsub -- allocates and returns a “fresh” substring from the string given as argument.
// strdup -- save a copy of a string
// strnew -- Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
// memalloc -- Allocates (with malloc(3)) and returns a “fresh” memory area.

static	int	find_new_line(int fd, char **buf, char **line)
{
	char		*new_line;
	char		*tmp;

	while ((new_line = ft_strchr(buf[fd], '\n')))
	{
		tmp = buf[fd];
		*new_line = '\0';
		*line = ft_strsub(buf[fd], 0, new_line - buf[fd]);
		buf[fd] = ft_strdup(new_line + 1);
		free(tmp);
		return (1);
	}
	while (*buf[fd])
	{
		*line = ft_strnew(ft_strlen(buf[fd]));
		ft_strcpy(*line, buf[fd]);
		buf[fd] = ft_memalloc(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

/*
** Reads into the heap, from the file descriptors, a specific number of bytes
** defined by the BUFF_SIZE macro in the get_nex_line.h file. It's going to
** continue the reading when the return value of the read function is greater
** than zero (no errors, or if there is nothing else to read).
** If there is something in the stack, we will concatinate whatever is in
** there, with whatever is read in the heap. If no, we will just add
** whatever is in the heap into the stack. Then we will verify the stack to
** see if there is a newline. If there is, we will break from the while loop
** and force the positive ret value into a one (1), using the RET_VALUE() macro.
** This answer form SO helped me visualize the stack and heap in a better way:
** http://stackoverflow.com/a/1213360
*/

static	int	ft_read(int fd, char **line)
{
	char		*buf;
	char		*tmp;
	int			i;

	buf = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!line[fd])
		{
			line[fd] = ft_strnew(ft_strlen(buf));
			ft_strcpy(line[fd], buf);
		}
		else
		{
			tmp = line[fd];
			line[fd] = ft_strjoin(line[fd], buf);
			free(tmp);
		}
		ft_memset(buf, 0, BUFF_SIZE);
	}
	free(buf);
	return (i);
}

/*
** Function for reading muiltiple files's lines line by line.
**
** The function reads & returns  the next line from a file refrenced  with   its
** file   descriptor,    everytime    the function is called. It  can  be called
** with  diffrent  file  descriptors,  it will alwats returns the next line.
**
**
** It first checks for errors (is the line is empty, if the number of the file
** descriptor is invalid, or if it fails to allocate the heap), so it can return
** a minus one (-1) if needed.
**
** If there is something in the stack (because we are using a static variable),
** we verify that there is a newline. If not, we allocate memory for the heap,
** and we read the file.
**
** When the reading of the file ends, we will free the heap (we're not gonna
** use it anymore), and we check for the value of ret (if it's 1 or -1, return
** that, if the stack is empty, return 0). If neither of these conditions are
** valid, we assing line to the value of the stack, free the stack, and return 1
**
** A good read about file descriptors:
** http://www.bottomupcs.com/file_descriptors.xhtml
**
** Return: 	
** -1 in case of an ERROR
** 1 in case of SUCCESS
** 0 for the end of file
*/

int			get_next_line(const int fd, char **line)
{
	static	char	*buf[FDS];

	if (!line || fd < 0 || BUFF_SIZE < 0 || (ft_read(fd, &buf[fd]) < 0) ||
fd > FDS)
		return (-1);
	if (find_new_line(fd, &buf[fd], line) == 1)
		return (1);
	return (0);
}