/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:11:08 by teva              #+#    #+#             */
/*   Updated: 2020/06/24 12:16:21 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct	s_flags
{
	int			dash;
	int			width;
	int			precision;
	int			dot;
	int			dot_star;
	int			dot_star_neg;
	int			star;
	int			zero;
	int			null;
}				t_flags;

int				ft_printf(const char *prnt, ...);
int				format_specifiers(char c, va_list ap, t_flags flags);
int				match_format_spec_flags(char *str, char c, t_flags flags);
int				is_format_spec(char c);
int				is_flag(char c);
int				if_null_char(char i, t_flags flags);
int				pf_string_or_num_precision(char **str, char c, t_flags flags);
int				pf_determine_width(char *str, t_flags flags);
int				pf_determine_width_char(t_flags flags);
int				pf_determine_string_precision(char **str, t_flags flags);
int				pf_determine_num_precision(char **str, t_flags flags);
int				treat_width(char *parsed);
int				treat_star(va_list ap, t_flags *flags);
int				pf_work_with_flags(char *str, char c, t_flags flags);
int				pf_char(va_list ap, t_flags *flags);
char			*pf_ptraddr(va_list ap);
char			*pf_hex(va_list ap, char c);
char			*pf_int(va_list ap);
char			*pf_str(va_list ap);
char			*pf_ui(va_list ap);
char			*if_neg(char *str, char **fill, t_flags flags);
char			*parse_flags(char *traverse, va_list ap, t_flags *flags);
char			*what_to_fill(char **str, char *fill, int diff, t_flags flags);
t_flags			flags_init(void);
t_flags			present_flags(char *parsed, va_list ap, t_flags flags);

#endif
