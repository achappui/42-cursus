/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:19:30 by achappui          #+#    #+#             */
/*   Updated: 2024/01/10 19:44:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>
# include "../../libs/libft/libft.h"

# define PACKET_NOT_READY	0
# define PACKET_READY		1

typedef struct s_packet
{
	size_t	bit_idx;
	size_t	len;
	char	*str;
}	t_packet;

#endif