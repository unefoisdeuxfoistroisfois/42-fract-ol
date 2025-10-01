# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: britela- <britela-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 16:14:38 by britela-          #+#    #+#              #
#    Updated: 2025/10/01 14:47:19 by britela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = fractol
SRC = main.c
OBJ = $(SRC:.c=.o)

# Détection OS
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	OS = LINUX
	MLX_DIR = minilibx-linux
	MLX_A = $(MLX_DIR)/libmlx_Linux.a
	MLX_INC = -I$(MLX_DIR)
	MLX_LINK = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else
	OS = MAC
	MLX_DIR = minilibx_opengl_20191021
	MLX_A = $(MLX_DIR)/libmlx.a
	MLX_INC = -I$(MLX_DIR)
	MLX_LINK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Flags
CFLAGS = -Wall -Wextra -Werror -g $(MLX_INC)
LDFLAGS = $(MLX_LINK)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_A)
	$(CC) $(OBJ) $(LDFLAGS) -o $@
	@echo "Built $(NAME) for $(OS)"

# .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build de la MiniLibX (selon OS)
$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJ)
	-$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	-$(RM) $(MLX_A)

re: fclean all

.PHONY: all clean fclean re
