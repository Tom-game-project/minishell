# minishell
#
# - tests用 build rule
# - example用 build rule
# - src用 build rule

CC = cc
RM = rm


CC_VERSION = $(CC) --version
VALGRIND = valgrind
VALGRINDFLAGS := --leak-check=full --trace-children=yes --track-fds=yes -q --show-leak-kinds=all


RMFLAGS = -rf

CFLAGS = -Wextra -Werror -Wall -g
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
      src/list/str_list_split.c\
      src/list/str_list_map.c\
      src/list/str_list_search.c\
      src/list/str_list_get_elem.c\
      src/list/str_list_concat.c\
      src/list/str_list_clone.c\
      src/list/str_list_cut.c\
      src/list/str_list_in.c\


EXPAND_STRING_SRC = \
      src/expand_string/utils/in_double_quotation.c\
      src/expand_string/utils/in_single_quotation.c\
      src/expand_string/utils/is_valid_env_char.c\
      src/expand_string/utils/out_of_quotation.c\
      src/expand_string/utils/push_expand_env.c\
      src/expand_string/utils/push_str_group.c\
      src/expand_string/expand_string.c\


PARSER_SRC = \
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
      src/parser/clear_ast.c\
      src/parser/syntax_checker.c\

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
      src/dict/str_dict_remove.c\


PATH_SRC =\
      src/path/get_full_path.c\
      src/path/get_dir_list.c\
      src/path/gen_nondup_name.c\


EXEC_SRC=\
      src/exec/exec.c\
      src/exec/fd_write.c\
      src/exec/utils/exec_none_proc.c\
      src/exec/utils/exec_and_proc.c\
      src/exec/utils/exec_or_proc.c\
      src/exec/utils/exec_pipe_proc.c\
      src/exec/utils/exec_execve_wrap.c\
      src/exec/utils/exec_redirect_i_proc.c\
      src/exec/utils/exec_redirect_o_proc.c\
      src/exec/utils/exec_heredoc_o_proc.c\
      src/exec/heredoc/create_shadow_file.c\
      src/exec/heredoc/heredoc.c\


STRTOOLS_SRC = \
     src/strtools/ft_streq.c\


# 成果物には含めない
# TODO: testのときのみ含まれるようなruleを追加する
FOR_TEST_SRC=\
      src/list/str_list_dprint.c\
      tests/tom_parser_tools/print_ast.c\


SRC = \
	$(BUILD_IN_SRC)\
	$(LIST_SRC)\
	$(EXPAND_STRING_SRC)\
	$(DICT_SRC)\
	$(PATH_SRC)\
	$(EXEC_SRC)\
	$(FOR_TEST_SRC)\
	$(PARSER_SRC)\
	$(STRTOOLS_SRC)\


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
# MAIN_OBJ = $(MAIN:.c=.o)
TEST_OBJ = $(TEST_FILE:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ) $(LIBFT_NAME)
	$(CC) $(CFLAGS) \
		-DCOMMIT_HASH="$(shell git show --format='%h' --no-patch)" \
		-DBUILD_TIMESTAMP='$(shell date "+%Y/%m/%d-%H:%M:%S")'\
		-DCC_VERSION="$(shell $(CC) --version | head -n1)"\
		-Iinclude \
		-o $(NAME) \
		$(OBJ) $(MAIN) $(LIBFT_NAME) 

$(LIBFT_NAME): $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)

$(LIBFT_HEADER):
	git submodule init
	git submodule update

# ここにはあえてフラグをつけていない
test: cleantest $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	./test_

vtest: cleantest $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(VALGRIND) $(VALGRINDFLAGS) ./test_

example:
	$(CC) $(TEST_FLAGS) -o $(EXAMPLE_NAME) $(EXAMPLE_FILE)

%.o: %.c 
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

cleantest: 
	$(RM) $(RMFLAGS) $(TEST_OBJ)

clean:
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all

.PHONY: all test vtest clean fclean re example cleantest
