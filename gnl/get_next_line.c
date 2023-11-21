/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:16:39 by achappui          #+#    #+#             */
/*   Updated: 2023/11/21 11:45:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_to_eol_len(t_gnl_static *block, int fd)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (1)
	{
		if (!block->buff || block->buff[i] == '\0')
		{
			block->next = ft_read_next_block(fd);
			if (!block->next)
				return (-1);
			block = block->next;
			i = 0;
		}
		if (block->buff[i] == '\n')
			return (len + 1);
		else if (block->buff[i] == '\0' && block->buff[i + 1] == '\0')
			return (len);
		else
		{
			i++;
			len++;
		}
	}
}

char	*ft_fill_line_get_rest(char *line, t_gnl_static *block, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		if (!block->buff || block->buff[i] == '\0')
		{
			block = block->next;
			i = 0;
		}
		*line++ = block->buff[i++];
		len--;
	}
	*line = '\0';
	line = NULL;
	while (block->buff[len + i] != '\0')
		len++;
	if (len++)
	{
		line = (char *)malloc((len) * sizeof(char));
		if (line)
			while (--len >= 0)
				line[len] = block->buff[len + i];
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_static	s = {.buff = NULL, .next = NULL};
	char				*line;
	int					len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = ft_get_to_eol_len(&s, fd);
	if (len <= 0)
	{
		ft_free_update_rest(&s, NULL);
		return (NULL);
	}
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
	{
		ft_free_update_rest(&s, NULL);
		return (NULL);
	}
	ft_free_update_rest(&s, ft_fill_line_get_rest(line, &s, len));
	return (line);
}
