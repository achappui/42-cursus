/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:19:30 by achappui          #+#    #+#             */
/*   Updated: 2024/01/13 14:38:31 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include "../libs/libft/libft.h"

# define PACKET_NOT_READY	0
# define PACKET_READY		1

typedef struct s_com
{
	char	*packet;
	char	server_reached;
	int		server_pid;
}	t_com;

#endif