/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:29:56 by achappui          #+#    #+#             */
/*   Updated: 2023/11/23 10:34:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	50
# endif

typedef struct s_block
{
	char			buffer[BUFFER_SIZE];
	struct s_block	*next;
}	t_block;

typedef struct s_sinfo
{
	unsigned int	sindex;
	struct s_block	sblock;
}	t_sinfo;

t_block	*ft_read_next_block(int fd);
void	ft_freeblocks(t_block **blk);

#endif