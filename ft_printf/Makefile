# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: britela- <britela-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 01:37:34 by britela-          #+#    #+#              #
#    Updated: 2025/05/17 12:33:07 by britela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

NAME = libftprintf.a

SRC =	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
	ft_putnbr_16.c ft_putnbr_unsgined.c ft_pointer.cc 
 	
OBJ = 	ft_printf.o ft_putchar.o ft_putstr.o ft_putnbr.o \
	ft_putnbr_16.o ft_putnbr_unsgined.o ft_pointer.o

 	
RM = rm -rf

LIB = ar rcs 

all: $(NAME)

# Création de la librairie 
$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Suppression des fichiers objets
clean:
	$(RM) $(OBJ) #SUPPRESION OBJ 

#Suppresiond es fichieres objets et la librairie
fclean: clean
	$(RM) $(NAME) #SUPPRESION DES OBJ ET LIBFT.a POUR RECOMPILATION PROPRE

#Recompilation
re: fclean all
.PHONY: all clean fclean re 
