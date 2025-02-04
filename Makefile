# minishell
#
# - tests用 build rule
# - example用 build rule
# - src用 build rule

CC = cc
RM = rm
VALGRIND = valgrind
VALGRINDFLAGS := --leak-check=full --show-leak-kinds=all --trace-children=yes -q
RMFLAGS = -rf

CFLAGS = -Wextra -Werror -Wall
TEST_FLAGS = -g

SRC = \
	src/built-in/cd.c\
	src/built-in/dummy.c\
	src/built-in/echo.c\
	src/built-in/env.c\
	src/built-in/exit.c\
	src/built-in/export.c\
	src/built-in/pwd.c\
	src/built-in/unset.c\
	src/list/char_list_push.c\
	src/list/char_list_pop.c\
	src/list/char_list_len.c\
	src/list/char_list_print.c\
	src/list/char_list_init.c\
	src/list/char_list_get_elem.c\
	# src/parser/trim_spc

MAIN = \
	src/minishell.c


# test rule
TEST_FILE := tests/dummy_test.c
TEST_NAME = test_

# example rule
EXAMPLE_FILE := examples/dummy_example00.c
EXAMPLE_NAME = example_

LIBFT_DIR = src/libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a
LIBFT_HEADER = $(LIBFT_DIR)/libft.h

#########

OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)
TEST_OBJ = $(TEST_FILE:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ) $(LIBFT_NAME)
	$(CC) $(CFLAGS) -Iinclude -o $(NAME) $(OBJ) $(MAIN_OBJ) $(LIBFT_NAME)

$(LIBFT_NAME): $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)
$(LIBFT_HEADER):
	git submodule init
	git submodule update

# ここにはあえてフラグをつけていない
test: $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	./test_

vtest: $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(VALGRIND) $(VALGRINDFLAGS) ./test_

example:
	$(CC) $(TEST_FLAGS) -o $(EXAMPLE_NAME) $(EXAMPLE_FILE)

%.o: %.c 
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJ)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all

.PHONY: all test vtest clean fclean re example
