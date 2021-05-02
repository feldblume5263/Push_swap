# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/02 19:53:27 by junhpark          #+#    #+#              #
#    Updated: 2021/05/02 20:42:03 by junhpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_NAME			= checker
PUSH_SWAP_NAME			= push_swap

CC						= gcc

CHECKER_SRC_NAME		= checker.c \
						sort_by_size.c \
						prepare.c \
						markup.c \
						error.c \
						set_stack.c \
						operation.c \
						other_utils.c \
						print_stack.c \
						stack_utils.c \
						stack.c \
						sorting_utils.c \
						result.c \
						sort_by_idx.c \
						size_utils.c \
						free.c

PUSH_SWAP_SRC_NAME		= push_swap.c \
						sort_by_size.c \
						prepare.c \
						markup.c \
						error.c \
						set_stack.c \
						operation.c \
						other_utils.c \
						print_stack.c \
						stack_utils.c \
						stack.c \
						sorting_utils.c \
						result.c \
						sort_by_idx.c \
						size_utils.c \
						free.c

SRC_PATH = ./src

CHECKER_SRC = $(addprefix $(SRC_PATH)/, $(CHECKER_SRC_NAME))
PUSH_SWAP_SRC = $(addprefix $(SRC_PATH)/, $(PUSH_SWAP_SRC_NAME))

CHECKER_OBJ_NAME = $(CHECKER_SRC_NAME:.c=.o)
PUSH_SWAP_OBJ_NAME = $(PUSH_SWAP_SRC_NAME:.c=.o)

OBJ_PATH = ./obj

CHECKER_OBJ = $(addprefix $(OBJ_PATH)/, $(CHECKER_OBJ_NAME))
PUSH_SWAP_OBJ = $(addprefix $(OBJ_PATH)/, $(PUSH_SWAP_OBJ_NAME))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror

LIBFT	= ./libft.a

LIBS	= -L./libft -lft

RM	= rm -rf

all	: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME)	: $(CHECKER_OBJ) $(LIBFT)
	gcc -o $(CHECKER_NAME) $(CHECKER_OBJ) $(HEADER) $(CFLAG) $(LIBS)

$(PUSH_SWAP_NAME)	: $(PUSH_SWAP_OBJ) $(LIBFT)
	gcc -o $(PUSH_SWAP_NAME) $(PUSH_SWAP_OBJ) $(HEADER) $(CFLAG) $(LIBS)

$(LIBFT):
	$(MAKE) -C ./libft

clean	:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJ_PATH)

fclean	: clean
	$(MAKE) -C ./libft fclean
	rm -rf $(CHECKER_NAME) $(PUSH_SWAP_NAME)

re		: fclean all

.PHONY: all clean fclean re
