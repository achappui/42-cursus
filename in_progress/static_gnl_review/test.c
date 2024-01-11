/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:57:43 by achappui          #+#    #+#             */
/*   Updated: 2024/01/10 20:00:18 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	char	*test;

	test = get_next_line(0);
	while (test)
	{
		printf("%s\n", test);
		free(test);
		test = get_next_line(0);
	}
	if (!test)
	{
		printf("NULL\n");
	}
	//printf("%s\n", test);
	return (0);
}