/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:29:54 by achappui          #+#    #+#             */
/*   Updated: 2023/11/19 21:40:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_fill_line(char *line, t_sinfo *si, unsigned int index, int fd)
{
	t_block	*blocks;

	blocks = si->sblock[fd];
	while (1)
	{
		while (index < BUFFER_SIZE)
		{
			if (blocks->buffer[index] == '\n')
			{
				*line = '\n';
				si->sindex[fd] = index + 1;
				while (++index < BUFFER_SIZE)
					si->sblock[fd]->buffer[index] = blocks->buffer[index];
				return ;
			}
			else if (blocks->buffer[index] == '\0')
			{
				si->sindex[fd] = BUFFER_SIZE;
				return ;
			}
			*line++ = blocks->buffer[index++];
		}
		blocks = blocks->next;
		index = 0;
	}
}

int	ft_get_line_length(int fd, t_block *block, unsigned int index)
{
	int	len;

	if (!block)
		return (-1);
	block->next = NULL;
	len = 0;
	while (1)
	{
		while (index < BUFFER_SIZE)
		{
			if (block->buffer[index] == '\n')
				return (len + 1);
			else if (block->buffer[index] == '\0')
				return (len);
			len++;
			index++;
		}
		block->next = ft_read_next_block(fd);
		if (!block->next)
			return (-1);
		block = block->next;
		index = 0;
	}
}

char	*get_next_line(int fd)
{
	static t_sinfo	si = {.sindex = {[0 ...MAX_FD - 1] = BUFFER_SIZE}, \
							.sblock = {[0 ...MAX_FD - 1] = NULL}};
	char			*line;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD - 1)
		return (NULL);
	if (!si.sblock[fd])
		si.sblock[fd] = (t_block *)malloc(sizeof(t_block));
	line = NULL;
	len = ft_get_line_length(fd, si.sblock[fd], si.sindex[fd]);
	if (len > 0)
	{
		line = (char *)malloc((len + 1) * sizeof(char));
		if (line)
		{
			line[len] = '\0';
			ft_fill_line(line, &si, si.sindex[fd], fd);
		}
	}
	else
		si.sindex[fd] = BUFFER_SIZE;
	ft_free_all(&si.sblock[fd]->next, &si, fd);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int fd1 = open("test", O_RDONLY);
	printf("LINE 1: %s\n\n", get_next_line(fd1));
	printf("LINE 2: %s\n\n", get_next_line(fd1));
	int fd2 = open("test1", O_RDONLY);
	printf("LINE 1: %s\n\n", get_next_line(fd2));
	printf("LINE 2: %s\n\n", get_next_line(fd2));
	close(fd1);
	close(fd2);
	return (0);
}