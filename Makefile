##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##


SRC     	=	./src/main.c 	\

OBJ	=    $(SRC:.c=.o)

CFLAGS	= -I include -W -Wall -g

LDFLAGS	=  -lm

NAME	= mysh

all:   	$(NAME)

$(NAME):        $(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) -L./lib/my -lmy -lm
clean:
		rm -f *.o
fclean:		clean
	        rm -f $(NAME)

re:     fclean all

