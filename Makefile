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

MAIN = \
      src/minishell.c


# test rule
TEST_FILE := tests/dummy_test.c
TEST_NAME = test_

# example rule
EXAMPLE_FILE := examples/dummy_example00.c
EXAMPLE_NAME = example_

#########

OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)
TEST_OBJ = $(TEST_FILE:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -Iinclude -o $(NAME) $(OBJ) $(MAIN_OBJ)

# ここにはあえてフラグをつけていない
test: $(OBJ) $(TEST_OBJ)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ)
	./test_

vtest: $(OBJ) $(TEST_OBJ)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ)
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
