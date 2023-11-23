/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:03 by achappui          #+#    #+#             */
/*   Updated: 2023/11/23 10:04:38 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			size++;
		s++;
	}
	return (size);
}

static char	**ft_split_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	size_t			len;

	tab = (char **)malloc((ft_split_size(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] != c && s[len] != '\0')
			len++;
		if (len)
		{
			tab[i] = ft_substr(s, 0, len);
			if (!tab[i++])
				return (ft_split_free(tab));
		}
		s += len;
	}
	tab[i] = NULL;
	return (tab);
}
