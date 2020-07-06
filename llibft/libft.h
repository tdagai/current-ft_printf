/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:55:51 by tdagai            #+#    #+#             */
/*   Updated: 2020/07/03 12:52:00 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef union		u_sbit
{
	double			d;
	uint64_t		i;
}					t_signbit;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(char *str);
int					ft_signbit(double x);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_lstsize(t_list *lst);
int					ft_putstr(char const *s);
int					ft_parse_digits(long long int i, int base);
int					ft_left_of_dot(long double dbl);
char				*ft_dtoa(long double d, size_t prec, int base);
//char				*ft_dtoa_for_g(char **str1, long double d, size_t prec,\
//					int base);
char				*ft_itoa(int i);
char				*ft_itoa_base(long long int i, int base);
char				*ft_itoa_base_unsigned(unsigned long long int i, int base);
char				*ft_realloc(char **ptraddr, size_t size);
char				*ft_downsize(char *str, int size);
char				*ft_strappend_change_first(char **dest, const char *src);
char				*ft_strappend_change_second(const char *str, char **dest);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *str);
char				*ft_strfill(char *str, char fill, size_t len);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t n);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(const char *s, char c);
char				**ft_split_funcs(char *str, const char *charset);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *offset, size_t n);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_lstdelone(t_list **lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				*ft_memset(void *offset, int x, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlen_for_e(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
t_list				*ft_lstnew(void const *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)\
					(void *));
long long int		ft_ceil(long double dbl);
long long int		ft_floor(long double dbl);
long long int		ft_abs(long long int lli);
long double			ft_round(long double dbl, int precision);
long double			ft_round_digits(long double dbl, int precision);
long double			ft_round_rval(long double dbl, int precision);
long double			ft_pow(long double dbl, long double pwr);
long double			ft_abs_dbl(long double dbl);

#endif
