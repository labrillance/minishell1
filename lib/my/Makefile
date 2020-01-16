##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file
##

SRC	=	my_putchar.c 		\
		my_putstr.c \
		my_strlen.c \
		my_strcat.c \


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re:	clean all

.PHONY: all clean fclean re
