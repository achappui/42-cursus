/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:29:16 by marvin            #+#    #+#             */
/*   Updated: 2024/01/06 18:29:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/libft/libft.h"

# define WHITE_SPACES	" \t\n\v\f\r"
# define INVALID		LLONG_MAX

typedef struct s_fdfinput
{
	long long		**map;
	unsigned int	line_len;
	unsigned int	col_len;
}	t_fdfinput;

void		free_inputs(t_fdfinput *inputs);
void		error_handler(t_list *list, void *to_free, char **split_to_free);
long long	validate_int(const char *s);
void		input_handler(int argc, char *argv[], t_fdfinput *inputs);
void	parse_file_content(int fd, t_list *begin, t_list *list, t_fdfinput *inputs);

#endif