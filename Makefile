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
				./src/env_manage.c \
				./src/my_strcmp.c \
				./src/shell_manage.c \
				./src/cd_function_manage.c \
				./src/parting_options.c \
				./src/error_handling.c \
				./src/no_path_parting.c \

OBJ	=    $(SRC:.c=.o)

CFLAGS	= -I include -W -Wall -g

NAME	= mysh

all:   	$(NAME)

$(NAME):        $(OBJ)
		make -C ./lib/my re
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) -L./lib/my -lmy 
clean:
		rm -f ./src/*.o
		make -C ./lib/my/ clean
fclean:		clean
	        rm -f $(NAME)

re:     fclean all
