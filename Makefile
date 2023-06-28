# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 11:42:09 by wnaiji            #+#    #+#              #
#    Updated: 2023/06/28 19:08:47 by walidnaiji       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	parsing.c \
	outils.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

NAME = pipex

CFLAGS = -Werror -Wextra -Wall #-fsanitize=address -g3
SUCCESS_MSG = "\033[0;32mCompilation successful. $(NAME) created.\033[0m\n"
ERROR_MSG = "\033[0;31mCompilation failed.\033[0m\n"
LIBFT_PATH = ./Libft/
FT_PRINTF_PATH = ./Ft_Printf/
GNL = ./Get_Next_Line/

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -I . -c $< -o $@
	@printf "             \rCompiling: $<"

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(FT_PRINTF_PATH)
	@make -C $(GNL)
	@gcc $(CFLAGS) -L $(LIBFT_PATH) -l ft -L $(FT_PRINTF_PATH) -l ftprintf \
		-L $(GNL) -l get_next_line $(OBJS) -o $(NAME)
	@printf "\n"
	@printf $(SUCCESS_MSG)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)
	@make clean -C $(GNL)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)
	@make fclean -C $(GNL)

re: fclean all

.PHONY: all clean fclean re
