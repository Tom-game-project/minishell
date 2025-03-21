# minishell
#
# - tests用 build rule
# - example用 build rule
# - src用 build rule

CC = cc
RM = rm

CC_VERSION = $(CC) --version
VALGRIND = valgrind
VALGRINDFLAGS := --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all

#--show-leak-kinds=all

RMFLAGS = -rf

CFLAGS = -Wextra -Werror -Wall
DEBUGFLAGS = -g -DDEBUG
TEST_FLAGS = -g


BUILD_IN_SRC = \
      src/built-in/cd.c\
      src/built-in/echo.c\
      src/built-in/env.c\
      src/built-in/exit.c\
      src/built-in/export.c\
      src/built-in/pwd.c\
      src/built-in/unset.c\
      src/built-in/build_in.c\


CHAR_LIST = \
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
      src/list/char_list_cut.c\
      src/list/char_list_search.c\



STR_LIST = \
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
      src/list/str_list_trim.c\
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
      src/list/candy_cutter.c\


INT_LIST = \
      src/list/int_list_len.c\
      src/list/int_list_push.c\
      src/list/int_list_print.c\
      src/list/int_list_init.c\
      src/list/int_list_clear.c\
      src/list/int_list_pop.c\
      src/list/int_list_insert.c\


VOID_LIST = \
      src/list/void_list_init.c\
      src/list/void_list_push.c\
      src/list/void_list_clear.c\
      src/list/void_list_print.c\
      src/list/void_list_get_back.c\
      src/list/void_list_len.c\
      src/list/void_list_get_elem.c\
      src/list/void_list_insert.c\
      src/list/void_list_pop.c\
      src/list/void_list_map.c\
      src/list/void_list_search.c\
      src/list/void_list_concat.c\
      src/list/void_list_cut.c\
      src/list/void_list_sort.c\
      src/list/void_list_insert_list.c\
      src/list/void_list_filter.c\


LIST_SRC = \
     $(INT_LIST)\
     $(CHAR_LIST)\
     $(STR_LIST)\
     $(VOID_LIST)\


EXPAND_STRING_SRC = \
      src/expand_string/utils/in_double_quotation.c\
      src/expand_string/utils/in_single_quotation.c\
      src/expand_string/utils/heredoc.c\
      src/expand_string/utils/out_of_quotation.c\
      src/expand_string/utils/push_expand_env.c\
      src/expand_string/utils/push_str_group.c\
      src/expand_string/expand_string.c\
      src/expand_string/heredoc_expand_string.c\


PARSER_SRC = \
      src/parser/parser.c\
      src/parser/parser_wrap.c\
      src/parser/allocation_ast.c\
      src/parser/checker_is.c\
      src/parser/checker_str.c\
      src/parser/find_chr.c\
      src/parser/separate_and_store_cmd_args.c\
      src/parser/separate_and_store_ctl_ope.c\
      src/parser/separate_and_store_rdt_ope.c\
      src/parser/separate_and_store_pipe_ope.c\
      src/parser/update_input.c\
      src/parser/trim_isspc.c\
      src/parser/clear_ast.c\
      src/parser/syntax_checker.c\


TOM_PARSER_SRC = \
      src/tom_parser/parser.c \
      src/tom_parser/tom_lexer.c\
      src/tom_parser/ope_collector.c\
      src/tom_parser/split_by_ifs.c\
      src/tom_parser/str2ope.c\
      src/tom_parser/init_ast.c\
      src/tom_parser/startswith_open_paren.c\
      src/tom_parser/is_rdt_string.c\
      src/tom_parser/is_ope_string.c\
      src/tom_parser/remove_ifs.c\
      src/tom_parser/syntax_checker.c\
      src/tom_parser/is_ifs.c\
      src/tom_parser/is_ope_char.c\


AST_CHECKER_SRC = \
      src/ast_checker/ast_checker.c\
      src/ast_checker/ast_checker_wrap.c\
      src/ast_checker/ast_checker_u.c\
      src/ast_checker/check_ctl_adjacent.c\
      src/ast_checker/check_rdt_no_arg.c\
      src/ast_checker/check_pipe_no_arg.c\
      src/ast_checker/print_checker_result.c\
      src/ast_checker/check_rdt_adjacent.c\
      src/ast_checker/check_element.c\
      src/ast_checker/check_adjacent_strings.c\
      src/ast_checker/check_no_input.c\


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
      src/path/create_shadow_file.c\
      src/path/get_full_path.c\
      src/path/get_dir_list.c\
      src/path/gen_nondup_name.c\
      src/path/is_executable_file.c\


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
      src/exec/utils/exec_heredoc_i_proc.c\
      src/exec/utils/exec_paren_proc.c\
      src/exec/utils/exec_sequential.c\
      src/exec/utils/exec_rdt.c\
      src/exec/heredoc/heredoc.c\
      src/exec/heredoc/heredoc_proc.c\
      src/exec/heredoc/close_all_heredoc_fd.c\
      # src/exec/asterisk/expand.c\


ENVTOOLS_SRC = \
      src/envtools/is_valid_env_char.c\
      src/envtools/is_valid_identifier.c\
      src/envtools/get_key_from_envp_ptr.c\
      src/envtools/get_value_from_envp_ptr.c\
      src/envtools/update_exit_status.c\


STRTOOLS_SRC = \
     src/strtools/ft_streq.c\
     src/strtools/includes_newline.c\
     src/strtools/remove_quotation.c\


LOOP_SRC = \
     src/loop/main_loop.c


SIG_SRC = \
     src/sig/disable_ctrl_backslash.c\
     src/sig/disconnect2stdin.c\
     src/sig/reconnect2stdin.c\
     src/sig/handler.c\
     src/sig/sig_setting.c\


TEST_TOOLS = \
     src/test_tools/print.c \
     src/test_tools/print_ast.c \
     src/test_tools/getpid.c\
     src/test_tools/getppid.c\
     src/list/str_list_dprint.c\


# 成果物には含めない
# TODO: testのときのみ含まれるようなruleを追加する
FOR_TEST_SRC=\
      tests/tom_parser_tools/print_ast.c\


SRC = \
	$(BUILD_IN_SRC)\
	$(LIST_SRC)\
	$(EXPAND_STRING_SRC)\
	$(DICT_SRC)\
	$(PATH_SRC)\
	$(EXEC_SRC)\
	$(STRTOOLS_SRC)\
	$(ENVTOOLS_SRC)\
	$(LOOP_SRC)\
	$(SIG_SRC)\
	$(TEST_TOOLS)\
	$(TOM_PARSER_SRC)\
	$(PARSER_SRC)\
	$(AST_CHECKER_SRC)\


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
TEST_OBJ = $(TEST_FILE:.c=.o)


NAME = minishell


all: $(NAME)


bonus: all


debug: CFLAGS+=$(DEBUGFLAGS)
debug: $(NAME)


# headerに含めるデバッグ情報
COMMIT_HASH = $(shell git show --format='%h' --no-patch)
BUILD_TIMESTAMP = $(shell date "+%Y\/%m\/%d-%H:%M:%S")
CC_VERSION = $(shell $(CC) --version | head -n1)


$(NAME): $(OBJ) $(LIBFT_NAME) $(MAIN)
	@cat $(MAIN) \
		| sed -e 's/^#define COMMIT_HASH$$/#define COMMIT_HASH ''"'$(COMMIT_HASH)'"''/' \
		| sed -e 's/^#define CC_VERSION$$/#define CC_VERSION "$(CC_VERSION)"/' \
		| sed -e 's/^#define BUILD_TIMESTAMP$$/#define BUILD_TIMESTAMP "$(BUILD_TIMESTAMP)"/' \
		| $(CC) $(CFLAGS) \
		-Iinclude \
		-o $(NAME) \
		$(OBJ) $(LIBFT_NAME) \
		-x c -\
		-lreadline


$(LIBFT_NAME): $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)


$(LIBFT_HEADER):
	git submodule init
	git submodule update


# ここにはあえてフラグをつけていない
test: cleantest debug $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(LIBFT_NAME) -lreadline
	./test_


vtest: cleantest debug $(OBJ) $(TEST_OBJ) $(LIBFT_NAME)
	$(CC) $(TEST_FLAGS) -Iinclude -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(LIBFT_NAME) -lreadline
	$(VALGRIND) $(VALGRINDFLAGS) ./test_


example:
	$(CC) $(TEST_FLAGS) -o $(EXAMPLE_NAME) $(EXAMPLE_FILE) -lreadline


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


.PHONY: all test vtest clean fclean re example cleantest debug
