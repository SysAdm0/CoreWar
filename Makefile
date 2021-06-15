##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

.PHONY: fclean all

all: COMPIL
COMPIL:
	@cd asm && make
	@cd corewar && make
clean:
	@cd asm && make clean
	@cd corewar && make clean
fclean:
	@cd asm && make fclean
	@cd corewar && make fclean
re: fclean all
