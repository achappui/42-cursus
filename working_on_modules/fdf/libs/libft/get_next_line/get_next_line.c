/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:29:54 by achappui          #+#    #+#             */
/*   Updated: 2023/11/22 14:25:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_fill_line(char *line, t_sinfo *si, unsigned int index)
{
	t_block	*blocks;

	blocks = &si->sblock;
	while (1)
	{
		while (index < BUFFER_SIZE)
		{
			if (blocks->buffer[index] == '\n')
			{
				*line = '\n';
				si->sindex = index + 1;
				while (++index < BUFFER_SIZE)
					si->sblock.buffer[index] = blocks->buffer[index];
				return ;
			}
			else if (blocks->buffer[index] == '\0')
			{
				si->sindex = BUFFER_SIZE;
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
	static t_sinfo	si = {.sindex = BUFFER_SIZE, .sblock.next = NULL};
	char			*line;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	len = ft_get_line_length(fd, &si.sblock, si.sindex);
	if (len > 0)
	{
		line = (char *)malloc((len + 1) * sizeof(char));
		if (line)
		{
			line[len] = '\0';
			ft_fill_line(line, &si, si.sindex);
		}
	}
	else
		si.sindex = BUFFER_SIZE;
	ft_freeblocks(&si.sblock.next);
	return (line);
}
