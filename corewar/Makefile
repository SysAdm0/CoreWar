##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

.PHONY: fclean all

SRC 	=	$(wildcard $(wildcard $(wildcard lib/*.c) src/*.c) src/instructions/*.c)

BONUS	=	$(wildcard bonus/*.c)

CFLAGS	=	-I./include -g3 -lncurses

NAME	=	corewar

all: COMPIL

COMPIL:	$(SRC:.c=.o)
	@gcc -o $(NAME) $(SRC) $(BONUS) $(CFLAGS)
	@echo "-> Done"

clean:
	rm -f lib/*.o
	rm -f src/*.o
	rm -f src/instructions/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all