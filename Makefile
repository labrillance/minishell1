##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##


SRC     	=	./src/main.c 	\
				./src/my_strcpy.c \
				./src/cpy_env.c \
				./src/clean_str.c \
				./src/check_error.c \

OBJ	=    $(SRC:.c=.o)

CFLAGS	= -I include -W -Wall -g

NAME	= mysh

all:   	$(NAME)

$(NAME):        $(OBJ)
		make -C ./lib/my re
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) -L./lib/my -lmy 
clean:
		rm -f *.o
fclean:		clean
	        rm -f $(NAME)

re:     fclean all
