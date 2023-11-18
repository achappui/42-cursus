/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:27:03 by achappui          #+#    #+#             */
/*   Updated: 2023/11/01 11:15:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_size(char const *s, char c)
{
	size_t			count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static int	ft_split_free(char **split_tab)
{
	int	i;

	i = 0;
	while (split_tab[i] != NULL)
		free(split_tab[i++]);
	free(split_tab);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**split_tab;
	unsigned int	i;
	size_t			len;

	i = 0;
	split_tab = (char **)malloc((ft_split_size(s, c) + 1) * sizeof(char *));
	if (split_tab == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] != '\0' && s[len] != c)
			len++;
		if (len != 0)
		{
			split_tab[i] = ft_substr(s, 0, len);
			if (split_tab[i++] == NULL && ft_split_free(split_tab))
				return (NULL);
		}
		s += len;
	}
	split_tab[i] = NULL;
	return (split_tab);
}
