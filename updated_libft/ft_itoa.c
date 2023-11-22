/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:03 by achappui          #+#    #+#             */
/*   Updated: 2023/11/22 17:39:40 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	uintptr_t	tab;
	short		i;

	tab = n;
	i = 1;
	while ((n >= 10 || n < 0) && i++)
		n /= 10;
	n = (int)tab;
	tab = (uintptr_t)malloc((i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	((char *)tab)[i] = '\0';
	((char *)tab)[0] = '-';
	while (n < 0)
	{
		((char *)tab)[--i] = -(n % 10) + 48;
		n /= 10;
	}
	while (i > 0)
	{
		((char *)tab)[--i] = n % 10 + 48;
		n /= 10;
	}
	return ((char *)tab);
}
