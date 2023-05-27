##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	my_hunter

CC		=	gcc -g3
RM		=	rm -rf

SRC		=	$(shell find src -type f -name "*.c")

OBJ		=	$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
LIB		=	-Llib/my -lmy -Iinclude
WARNING	=	-W -Wall -Wextra

$(NAME):
		make -C lib/my
		$(CC) -o $(NAME) $(SRC) $(WARNING) $(LIB) $(CSFML)
		rm lib/libmy.a
		rm lib/my/libmy.a
		make clean

all:	$(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
