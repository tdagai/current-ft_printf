/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:11:08 by teva              #+#    #+#             */
/*   Updated: 2020/07/06 13:52:26 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef	struct		s_flags
{
	int				dash;
	int				width;
	int				precision;
	int				dot;
	int				dot_star;
	int				dot_star_neg;
	int				star;
	int				zero;
	int				null;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				capital_l;
	int				pound;
	int				space;
	int				plus;
}					t_flags;

typedef struct		s_n_spec
{
	int				*i;
	short int		*si;
	signed char		*sc;
	long int		*li;
	long long int	*lli;
}					t_n_spec;

typedef struct		s_g_var
{
	char			*str_e;
	char			*str_f;
	double			dbl;
	int				prec;
	int				x;
}					t_g_var;

int					ft_printf(const char *prnt, ...);
int					format_specifiers(char c, int len, va_list ap,\
					t_flags flags);
int					match_format_spec_flags(char *str, char c, t_flags flags);
int					is_format_spec(char c);
int					is_num_spec(char c);
int					is_flag(char c);
int					if_null_char(char i, t_flags flags);
int					pf_string_or_num_precision(char **str, char c,\
					t_flags flags);
int					pf_determine_width(char *str, t_flags flags);
int					pf_determine_width_char(t_flags flags);
int					pf_determine_string_precision(char **str, t_flags flags);
int					pf_determine_num_precision(char **str, t_flags flags);
int					pf_float_precision(t_flags flags);
int					treat_width(char *parsed);
int					treat_star(va_list ap, t_flags *flags);
char				*ft_dtosci_for_g(int *exponent, long double dbl, int prec,\
					t_flags flags);
int					pf_work_with_flags(char *str, char c, t_flags flags);
int					pf_char(va_list ap, t_flags *flags);
int					pf_nothing(va_list ap, int len, t_flags flags);
char				*pf_ptraddr(va_list ap);
char				*pf_hex(va_list ap, char c, t_flags flags);
char				*pf_int(va_list ap, t_flags flags);
char				*pf_str(va_list ap, t_flags flags);
char				*pf_ui(va_list ap, t_flags flags);
char				*pf_floating_point(va_list ap, t_flags flags);
char				*pf_scientific_notation(va_list ap, char c, t_flags flags);
char				*pf_float_or_sci(va_list ap, char c, t_flags flags);
char				*if_neg(char *str, char **fill, t_flags flags);
char				*parse_flags(char *traverse, va_list ap, t_flags *flags);
char				*pf_tack_at_front(char *str, char c, t_flags flags);
char				*ft_dtosci(long double dbl, int prec, t_flags flags);
char				*what_to_fill(char **str, char *fill, int diff,\
					t_flags flags);
char				*ft_dtoa_for_g(long double dbl, size_t prec, int base);
t_flags				flags_init(void);
t_flags				present_flags(char *parsed, va_list ap, t_flags flags);
t_flags				if_dot(char *parsed, va_list ap, t_flags *flags);
t_flags				if_dash_or_star(char *parsed, va_list ap, t_flags *flags);
t_flags				if_bonus_flags(char *parsed, t_flags *flags);

#endif
