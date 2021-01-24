NAME	= libftprintf.a
SRCS	= ft_printf.c		\
		ft_itoa_base.c		\
		remplir_struct.c	\
		verif_arg.c 		\
		ft_utils.c			\
		aff_d.c		\
		aff_s.c				\
		aff_p.c				\
		aff_u.c				\
		aff_x.c				\
		aff_xx.c			\

CFLAGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

%.o:%.c
		gcc ${CFLAGS} -o $@ -c $< -I ft_printf.h

clean:		
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		clean fclean 
