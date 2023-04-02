##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## ouais
##

SRC	= 	load_2d_array_from_file.c 	\
		map_implement.c 			\
		my_strlen.c 				\
		my_show_word_array.c 		\
		my_putstr.c 				\
		my_putchar.c 				\
		my_numberlen.c 				\
		generate_map.c 				\
		my_strcpy.c

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mkdir -p ../../include
		cp $(NAME) ../
		cp my.h ../../include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
