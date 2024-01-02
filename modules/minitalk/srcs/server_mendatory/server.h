/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:29:34 by achappui          #+#    #+#             */
/*   Updated: 2024/01/02 11:06:14 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <time.h>
# include <limits.h>
# include "../../libs/libft/libft.h"

# define ASK_FIRST_BIT	0
# define GETTING_LEN	1
# define GETTING_STR	2
# define PROCESS_END	3

#endif