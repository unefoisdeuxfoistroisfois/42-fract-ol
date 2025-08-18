# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: britela- <britela-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 16:14:38 by britela-          #+#    #+#              #
#    Updated: 2025/08/18 22:39:32 by britela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = fractol

SRC = 	

OBJ = 

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    OS = LINUX
    MLX_FLAGS = -lmlx -L minilibx/ -lXext -lX11 -lm -lz
else
    OS = MAC
    MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -L minilibx/
   -I minilibx_opengl_20191021 -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
endif

RM = rm -rf
LIB = ar rcs # Création de la librairie

all: $(NAME)

# Création de la librairie 
$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Suppression des fichiers objets
clean:
	$(RM) $(OBJ) $(OBJBONUS) #SUPPRESION OBJ 

#Suppresiond es fichieres objets et la librairie
fclean: clean
	$(RM) $(NAME) #SUPPRESION DES OBJ ET LIBFT.a POUR RECOMPILATION PROPRE

#Recompilation
re: fclean all
.PHONY: all clean fclean re bonus
