# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: britela- <britela-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 11:58:37 by britela-          #+#    #+#              #
#    Updated: 2025/11/05 00:17:21 by britela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = fractol
SRC = mlx.c event.c mandel.c
OBJ = $(SRC:.c=.o)

LOGO = "\033[1;38;5;208m\
░▒▓████████▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░\n\
░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n\
░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n\
░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n\
░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n\
░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n\
░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  ░▒▓█▓▒░   ░▒▓██████▓▒░░▒▓████████▓▒░\n\
\033[0m"

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

# ft_printf
PRINTF_DIR  = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Flags
CFLAGS = -Wall -Wextra -Werror -g $(MLX_INC) -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_A)
	@printf "\n"
	@printf "\n"
	@printf "\n"
	@printf $(LOGO)
	@printf "\n"
	@printf "\n"
	@printf "\n"
	@echo "\033[1;32mLIASON DES OBJETS\033[0m"
	$(CC) $(OBJ) $(CFLAGS) -o $@ $(PRINTF) $(MLX_LINK)
	@echo "\033[1;32mCOMPILATION REUSSIE DE $(NAME) POUR $(OS) \033[0m"

# .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build de la MiniLibX (selon OS)
$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

# Build de ft_printf
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean 
	$(RM) $(NAME)
	$(RM) $(MLX_A)
	$(MAKE) -C $(PRINTF_DIR) clean

re: fclean all

.PHONY: all clean fclean re
