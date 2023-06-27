# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 17:46:04 by wnaiji            #+#    #+#              #
#    Updated: 2023/06/27 11:04:17 by wnaiji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
	  ft_printchar.c \
	  ft_printnbr.c \
	  ft_printstr.c \
	  ft_printnbr_base.c \
	  ft_lower_or_up_case.c \
	  ft_print_unsignednbr.c \
	  ft_printptr.c \
	  ft_strlen.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

NAME = libftprintf.a

CFLAGS = -Werror -Wextra -Wall
SUCCESS_MSG = "\033[0;32mCompilation successful. $(NAME) created.\033[0m\n"
ERROR_MSG = "\033[0;31mCompilation failed.\033[0m\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -I . -c $< -o $@
	@printf "                                              \rCompiling: $<"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "\n"
	@printf $(SUCCESS_MSG)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
