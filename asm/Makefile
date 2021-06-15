##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

.PHONY: fclean all

SRC 	=	$(wildcard src/*.c)

CFLAGS	=	-I./include -g3 -Wall

NAME	=	asm

all: COMPIL
COMPIL:	$(SRC:.c=.o)
	@gcc -o $(NAME) $(SRC) $(CFLAGS)
	@echo "-> Done"
clean:
	rm -f src/*.o
fclean: clean
	rm -f $(NAME)
re: fclean all