##
## EPITECH PROJECT, 2022
## dante
## File description:
## solver_Makefile
##

SRC	=	source/main.c \
		source/get_argv.c \
		source/error.c \
		source/my_str_to_word_array.c \
		source/my_array_len.c \
		source/print_array.c \
		source/a_star/manage_list.c \
		source/a_star/a_star.c \
		source/a_star/creat_neighbour.c \
		source/a_star/parsing_list.c \
		source/depth_first/depth_first.c \
		source/depth_first/dfs_creat_neighbour.c \
		source/depth_first/dfs_manage_list.c \

SRC_TEST =

TEST_FILE =

OBJ	=	$(SRC:.c=.o)

LIB = solver

all:	$(LIB)

$(LIB):
	@gcc -o $(LIB) $(SRC) -I ./include

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(LIB)

re: fclean $(OBJ)
	@gcc -o $(LIB) $(SRC) -I ./include

unit_tests: re
	@gcc -o unit_tests $(SRC_TEST) $(TEST_FILE) --coverage -lcriterion

run_tests: unit_tests
	./unit_tests
