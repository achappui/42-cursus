/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:03 by achappui          #+#    #+#             */
/*   Updated: 2023/11/01 10:28:07 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len_itoa(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	us_n;
	int				len;
	char			*tab;

	len = ft_get_len_itoa(n);
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	tab[len] = '\0';
	if (n < 0)
		us_n = -n;
	else
		us_n = n;
	while (len > 0)
	{
		tab[--len] = us_n % 10 + '0';
		us_n /= 10;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
