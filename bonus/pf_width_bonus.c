/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 09:35:39 by teva              #+#    #+#             */
/*   Updated: 2020/06/12 12:41:54 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		pf_determine_width(char *str, t_flags flags)
{
	if (flags.width > 0)
		return (flags.width);
	else if (flags.star > 0)
		return (flags.star);
	else
		return (ft_strlen(str));
}

int		pf_determine_width_char(t_flags flags)
{
	if (flags.width > 0)
		return (flags.width);
	else if (flags.star > 0)
		return (flags.star);
	else
		return (1);
}
