##
## EPITECH PROJECT, 2022
## zoijr
## File description:
## ouais
##

SRC		=	bsq.c

OBJ		=	$(SRC:.c=.o)

NAME 	= 	bsq

LDFLAGS	=	-L./lib/ -lmy -g

CFLAGS=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:
		make clean
		rm -f unit_tests
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
