#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: migalvar <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/25 18:09:20 by migalvar      #+#    #+#                  #
#    Updated: 2020/02/20 19:03:08 by migalvar      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_printf.c printf_utils_one.c printf_utils_two.c printf_utils_three.c\
		printf_utils_four.c print_call.c

OBJ = $(SRC:.c=.o)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
