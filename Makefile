# minishell
#
# - tests用 build rule
# - example用 build rule
# - src用 build rule

CC = cc
CFLAGS = -Wextra -Werror -Wall

SRC = \
      src/built-in/dummy.c\
      src/minishell.c

OBJ = $(SRC:.c=.o)


NAME = minishell

all: $(OBJ)
	$(CC) $(CFLAGS) -Iinclude -o $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

.PHONY: all
