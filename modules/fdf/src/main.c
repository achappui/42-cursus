/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:28:57 by marvin            #+#    #+#             */
/*   Updated: 2024/01/06 18:28:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdfinput	inputs;

	input_handler(argc, argv, &inputs);
	// unsigned int	i;
	// i = 0;
	// unsigned int	j;
	// while (i < inputs.col_len)
	// {
	// 	j = 0;
	// 	while (j < inputs.line_len)
	// 	{
	// 		printf("%d,%X ", (int)(inputs.map[i][j] >> 32), (unsigned int)(inputs.map[i][j]));
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	free_inputs(&inputs);
	return (0);
}