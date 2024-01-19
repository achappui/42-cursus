/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:16:36 by achappui          #+#    #+#             */
/*   Updated: 2023/11/21 15:10:53 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_gnl_block	*ft_read_next_block(int fd)
{
	t_gnl_block	*new_elem;
	ssize_t		read_bytes;

	new_elem = (t_gnl_block *)malloc(sizeof(t_gnl_block));
	if (new_elem == NULL)
		return (NULL);
	new_elem->buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (new_elem->buff == NULL)
	{
		free(new_elem);
		return (NULL);
	}
	read_bytes = read(fd, new_elem->buff, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		free(new_elem->buff);
		free(new_elem);
		return (NULL);
	}
	((char *)new_elem->buff)[read_bytes] = '\0';
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_free_update_rest(t_gnl_block *s, char *rest)
{
	t_gnl_block	*next;
	t_gnl_block	*blocks;

	blocks = s->next;
	if (rest)
	{
		if (s->buff)
			free(s->buff);
		s->buff = rest;
	}
	else
	{
		if (s->buff)
			free(s->buff);
		s->buff = NULL;
	}
	while (blocks)
	{
		next = blocks->next;
		free(blocks->buff);
		free(blocks);
		blocks = next;
	}
	s->next = NULL;
}
