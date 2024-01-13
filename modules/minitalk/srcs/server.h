/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:29:34 by achappui          #+#    #+#             */
/*   Updated: 2024/01/13 14:38:32 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include "../libs/libft/libft.h"

# define ASK_FIRST_BIT	0
# define GETTING_LEN	1
# define GETTING_STR	2
# define PROCESS_END	3

typedef struct s_reception
{
	unsigned int	len;
	char			*str;
	char			state;
	int				client_pid;
}	t_reception;

#endif