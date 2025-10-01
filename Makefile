# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: britela- <britela-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 16:14:38 by britela-          #+#    #+#              #
#    Updated: 2025/10/01 09:53:12 by britela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC      = cc
NAME    = fractol
SRC     = main.c
CFLAGS		= -Wall -Wextra -Werror -g

# Détection OS
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    OS = LINUX
    MLX_FLAGS = -lmlx -L minilibx-linux/ -lXext -lX11 -lm -lz
else
    OS = MAC
    MLX_FLAGS = -I minilibx_opengl_20191021/ -L minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./minilibx_opengl_20191021
	$(CC) $(SRC) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
.PHONY: all clean re
