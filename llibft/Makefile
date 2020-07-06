# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdagai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 18:58:42 by tdagai            #+#    #+#              #
#    Updated: 2020/06/23 15:51:16 by teva             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c		ft_lstnew.c		ft_memset.c		ft_putstr_fd.c		ft_strequ.c\
	  ft_strncat.c		ft_split_funcs.c				ft_isprint.c		ft_memalloc.c\
	  ft_putchar.c		ft_strcat.c		ft_striter.c	ft_strncmp.c		ft_strstr.c\
	  ft_itoa.c			ft_memccpy.c	ft_putchar_fd.c	ft_strchr.c			ft_striteri.c\
	  ft_strncpy.c		ft_substr.c		ft_atoi.c		ft_lstadd.c			ft_memchr.c\
	  ft_putendl.c		ft_strclr.c		ft_strjoin.c	ft_strnequ.c		ft_strtrim.c\
	  ft_bzero.c		ft_lstclear.c	ft_memcmp.c		ft_putendl_fd.c		ft_strcmp.c\
	  ft_strlcat.c		ft_strnew.c		ft_tolower.c	ft_isalnum.c		ft_lstdelone.c\
	  ft_memcpy.c		ft_putnbr.c		ft_strcpy.c		ft_strlen.c			ft_strnstr.c\
	  ft_toupper.c		ft_isalpha.c	ft_lstiter.c	ft_memdel.c			ft_putnbr_fd.c\
	  ft_strdel.c		ft_strmap.c		ft_strrchr.c	ft_isascii.c		ft_lstmap.c\
	  ft_memmove.c		ft_putstr.c		ft_strdup.c		ft_strmapi.c		ft_split.c\
	  ft_calloc.c		ft_strlcpy.c	ft_lstadd_front.c					ft_itoa_base.c\
	  ft_itoa_base_unsigned.c			ft_pow.c		ft_round.c			ft_strappend.c\
	  ft_realloc.c		ft_dtoa.c		ft_strfill.c	ft_downsize.c		ft_abs.c\
	  ft_lstadd_back.c	ft_signbit.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@-gcc -Wall -Wextra -Werror -c $(SRC)
	ar rcs $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

