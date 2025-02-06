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

BUILD_IN_SRC = \
      src/built-in/cd.c\
      src/built-in/dummy.c\
      src/built-in/echo.c\
      src/built-in/env.c\
      src/built-in/exit.c\
      src/built-in/export.c\
      src/built-in/pwd.c\
      src/built-in/unset.c\


LIST_SRC = \
      src/list/char_list_push.c\
      src/list/char_list_pop.c\
      src/list/char_list_len.c\
      src/list/char_list_print.c\
      src/list/char_list_init.c\
      src/list/char_list_get_elem.c\
      src/list/char_list_get_ptr.c\
      src/list/char_list_insert.c\
      src/list/char_list_insert_str.c\
      src/list/char_list_get_back.c\
      src/list/char_list_clear.c\
      src/list/char_list_to_str.c\
      src/list/char_list_is_empty.c\
      src/list/str_list_init.c\
      src/list/str_list_get_ptr.c\
      src/list/str_list_get_back.c\
      src/list/str_list_push.c\
      src/list/str_list_pop.c\
      src/list/str_list_print.c\
      src/list/str_list_len.c\
      src/list/str_list_clear.c\
      src/list/str_list_to_str.c\
      src/list/str_list_to_array.c\
      src/list/str_list_len_sum.c\
      src/list/str_list_join.c\


PARSER_SRC = \
      src/parser/expand_string/in_double_quotation.c\
      src/parser/expand_string/in_single_quotation.c\
      src/parser/expand_string/is_valid_env_char.c\
      src/parser/expand_string/out_of_quotation.c\
      src/parser/expand_string/push_expand_env.c\
      src/parser/expand_string/push_str_group.c\
      src/parser/expand_string.c\
      src/parser/parser.c\
      src/parser/allocation_ast.c\
      src/parser/checker_is.c\
      src/parser/checker_str.c\
      src/parser/find_chr.c\
      src/parser/separate_and_store_cmd_args.c\
      src/parser/separate_and_store_ctl_ope.c\
      src/parser/separate_and_store_rdt_ope.c\
      src/parser/update_input.c\
      src/parser/trim_isspc.c\


DICT_SRC = \
      src/dict/envp_to_str_dict.c\
      src/dict/str_dict_init.c\
      src/dict/str_dict_set.c\
      src/dict/str_dict_add.c\
      src/dict/str_dict_push.c\
      src/dict/str_dict_print.c\
      src/dict/str_dict_get_back.c\
      src/dict/str_dict_key.c\
      src/dict/str_dict_clear.c\
      src/dict/str_dict_len.c\
      src/dict/str_dict_to_env.c\


SRC = \
	$(BUILD_IN_SRC)\
	$(LIST_SRC)\
	$(PARSER_SRC)\
	$(DICT_SRC)


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
	make fclean -C $(LIBFT_DIR)
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all

.PHONY: all test vtest clean fclean re example
