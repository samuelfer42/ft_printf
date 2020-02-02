# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safernan <safernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 17:15:04 by safernan          #+#    #+#              #
#    Updated: 2020/01/29 17:52:00 by safernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

SRC = ft_printf.c			\
		ft_itoa_base.c		\
		remplir_structure.c	\
		ft_printarg.c 		\
		atoi.c				\
		aff_d.c		\
		aff_s.c				\
		aff_p.c				\
		aff_u.c				\
		aff_x.c				\
		aff_xx.c			\

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33mCompiling -> \033[0;32m [OK]"
	@$(CC) $(SRC) -I ./ $(CFLAGS)
	@ar r $(NAME) $(OBJ)
	@echo "\033[0;36m ---> READY "
	
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<  -I .

clean:
	@echo "\033[0;33mClean ->\033[0;32m [OK]"
	@rm -f $(OBJ)
	@rm -f *.gch

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mRemoval $(NAME) ->\033[0;32m [OK]"

re: fclean all

	
norme:
	@echo "\033[0;32mNorminette ->"
	@norminette *.c

	
.PHONY: clean fclean
