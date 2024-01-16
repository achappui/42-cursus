/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:03 by achappui          #+#    #+#             */
/*   Updated: 2023/11/01 10:29:12 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	s_dup = (char *)malloc((len + 1) * sizeof(char));
	if (s_dup == NULL)
		return (NULL);
	s_dup += len;
	while (len-- > 0)
		*s_dup-- = *s--;
	*s_dup = *s;
	return (s_dup);
}
