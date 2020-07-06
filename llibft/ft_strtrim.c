/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:50:01 by tdagai            #+#    #+#             */
/*   Updated: 2020/04/17 17:21:09 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_start(char const *s1, char const *set)
{
	int	start;
	int set_ctr;

	start = 0;
	while (s1[start])
	{
		set_ctr = 0;
		while (set[set_ctr])
		{
			if (set[set_ctr] == s1[start])
			{
				start++;
				break ;
			}
			else
				set_ctr++;
		}
		if (set[set_ctr] == '\0')
			break ;
	}
	return (start);
}

static int		check_end(char const *s1, char const *set)
{
	int	end;
	int set_ctr;

	end = ft_strlen(s1) - 1;
	while (s1[end])
	{
		set_ctr = 0;
		while (set[set_ctr])
		{
			if (set[set_ctr] == s1[end])
			{
				end--;
				break ;
			}
			else
				set_ctr++;
		}
		if (set[set_ctr] == '\0')
			break ;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1)
		return (NULL);
	start = check_start(s1, set);
	end = check_end(s1, set);
	if (start >= end)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strnew(end - start + 1)))
			return (NULL);
	}
	ft_strncpy(str, (s1 + start), (end - start + 1));
	return (str);
}
