# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 17:18:05 by sjones            #+#    #+#              #
#    Updated: 2017/12/02 20:21:14 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
LFT = -L libft -lft
SRC_PATH =	src
SRC_NAME =	main.c \
			error.c \
			init.c \
			map.c \
			test.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ =	$(SRC_NAME:%.c=%.o)
INCL = src/wolf3d.h
all: $(NAME)

$(NAME):
	@echo "\033[1;33mWolf3d: Sources compiling... \033[0m"
	@make -C libft/
	@$(CC) $(FLAGS) -I $(INCL) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LFT) $(MLX)
	@echo "\033[1;34mWolf3d: Compiled with success..!\033[0m"

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ)
	@echo "\033[0;36mObjects removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[0;36mWolf3d binary removed...\033[0m"

re: fclean all
