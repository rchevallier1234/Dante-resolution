##
## EPITECH PROJECT, 2023
## B-CPE-110-NAN-1-1-antman-nicolas2.bertrand
## File description:
## Makefile
##

all:
	@make -C solver

clean:
	@make clean -C solver

fclean:
	@make fclean -C solver

re:	fclean all
