/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:29:52 by achappui          #+#    #+#             */
/*   Updated: 2023/11/20 01:04:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_block	*ft_read_next_block(int fd)
{
	t_block	*new_block;
	ssize_t	read_bytes;

	new_block = (t_block *)malloc(1 * sizeof(t_block));
	if (new_block == NULL)
		return (NULL);
	read_bytes = read(fd, new_block->buffer, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		free(new_block);
		return (NULL);
	}
	else if (read_bytes < BUFFER_SIZE)
		new_block->buffer[read_bytes] = '\0';
	new_block->next = NULL;
	return (new_block);
}

void	ft_free_all(t_block **block, t_sinfo *si, int fd)
{
	t_block	*next;

	while (*block != NULL)
	{
		next = (*block)->next;
		free(*block);
		*block = next;
	}
	*block = NULL;
	if (si->sindex[fd] == BUFFER_SIZE && si->sblock[fd] != NULL)
	{
		free(si->sblock[fd]);
		si->sblock[fd] = NULL;
	}
}
