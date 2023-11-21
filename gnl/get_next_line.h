/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:16:41 by achappui          #+#    #+#             */
/*   Updated: 2023/11/21 11:48:22 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	50
# endif

typedef struct s_gnl_block
{
	char				buff[BUFFER_SIZE + 2];
	struct s_gnl_block	*next;
}	t_gnl_block;

typedef struct s_gnl_static
{
	char				*buff;
	struct s_gnl_block	*next;
}	t_gnl_static;

t_gnl_block	*ft_read_next_block(int fd);
void		ft_free_update_rest(t_gnl_static *s, char *rest);
char		*get_next_line(int fd);

#endif