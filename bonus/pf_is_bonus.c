/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_is_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 09:59:40 by teva              #+#    #+#             */
/*   Updated: 2020/06/23 12:54:45 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_format_spec(char c)
{
	return (c == 'c' || c == 'i' || c == 'd' || c == 's' || c == 'u' ||\
			c == 'p' || c == 'x' || c == 'X' || c == '%' || c == 'n' ||\
			c == 'f' || c == 'e' || c == 'E' || c == 'g' || c == 'G');
}

int		is_flag(char c)
{
	return (c == '-' || c == '*' || c == '.' || (c >= '0' && c <= '9') ||\
			c == '#' || c == 'l' || c == 'h' || c == 'L' || c == ' ' ||\
			c == '+');
}

int		is_num_spec(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' ||\
			c == 'f' || c == 'e' || c == 'E' || c == 'g' || c == 'G');
}
