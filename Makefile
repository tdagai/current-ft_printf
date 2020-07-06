# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdagai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 18:58:42 by tdagai            #+#    #+#              #
#    Updated: 2020/06/28 19:50:52 by teva             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC = src/pf_flags_with.c	src/pf_prec.c\
	  src/pf_simple_types.c	src/ft_printf.c\
	  src/pf_hard_types.c	src/pf_is.c\
	  src/pf_flags.c		src/pf_treat_flags.c\
	  src/pf_width.c
	  
SRC_BONUS =	bonus/pf_flags_with_bonus.c		bonus/pf_prec_bonus.c\
	  		bonus/pf_simple_types_bonus.c	bonus/ft_printf_bonus.c\
	  		bonus/pf_hard_types_bonus.c		bonus/pf_is_bonus.c\
	  		bonus/pf_flags_bonus.c			bonus/pf_treat_flags_bonus.c\
	  		bonus/pf_width_bonus.c			bonus/pf_types_bonus.c\
			bonus/pf_dtosci_bonus.c			bonus/pf_if_bonus.c\

.PHONY: all clean fclean re bonus

all: bonus

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rcs $(NAME) *.o libft/libft.a
	ranlib $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC_BONUS)
	ar rcs $(NAME) *.o libft/libft.a
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

