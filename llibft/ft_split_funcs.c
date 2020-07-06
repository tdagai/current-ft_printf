/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:52:17 by tdagai            #+#    #+#             */
/*   Updated: 2020/04/16 12:08:03 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_delim(char c, const char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int		word_count(char *str, const char *charset)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i] && is_delim(str[i], charset))
		i++;
	if (str[i] && !is_delim(str[i], charset))
		count = 1;
	while (str[i])
	{
		if (!is_delim(str[i], charset) && !is_delim(str[i - 1], charset))
			count++;
		i++;
	}
	return (count);
}

static int		word_size(char *str, const char *charset)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (str[i] && !is_delim(str[i], charset))
	{
		size++;
		i++;
	}
	return (size);
}

char			**ft_split_funcs(char *str, const char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	if (!(tab = (char **)malloc(sizeof(char *) *
					(word_count(str, charset) + 1))))
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!is_delim(str[i], charset))
		{
			if (index == -1 || is_delim(str[i - 1], charset))
			{
				if (!(tab[++index] = (char *)malloc(sizeof(char) *
								word_size(str + i, charset) + 1)))
					return (NULL);
				j = 0;
			}
			tab[index][j] = str[i];
			tab[index][++j] = '\0';
		}
	tab[++index] = 0;
	return (tab);
}
