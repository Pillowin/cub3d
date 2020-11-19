# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 18:59:05 by agautier          #+#    #+#              #
#    Updated: 2020/11/16 22:51:28 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Cub3D
SRC			=	$(wildcard src/*.c)
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
CFLAGS		=	-fsanitize=address -g3 -Wall -Wextra -Werror 
HEADER_DIR	=	header
LIB_DIR		=	lib
LIBS		=	-lft -lm -lmlx -lXext -lX11

all: $(NAME)

$(NAME): libft mlx $(OBJ)
	@echo -n "Génération de $(NAME)"
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -L$(LIB_DIR) -o $@ $(OBJ) $(LIBS)
	@echo "\033[32m\t\t\t\t[OK]\033[0m"

%.o: %.c
	@echo -n "Génération du fichier $@"
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -L$(LIB_DIR) -c $< -o $@ $(LIBS)
	@echo "\033[32m\t\t[OK]\033[0m"

libft:
	@echo -n "Génération de la libft"
	@make -s -C lib/libft
	@echo "\033[32m\t\t\t\t[OK]\033[0m"
	@echo -n "Copie du fichier libft.a"
	@cp lib/libft/libft.a lib/libft.a
	@echo "\033[32m\t\t\t[OK]\033[0m"

mlx:
	@echo -n "Génération de la minilibx "
	@make -s -C lib/minilibx-linux > /dev/null
	@echo "\033[32m\t\t\t[OK]\033[0m"
	@echo -n "Copie du fichier libmlx.a"
	@cp lib/minilibx-linux/libmlx_Linux.a lib/libmlx.a
	@echo "\033[32m\t\t\t[OK]\033[0m"

clean:
	@echo -n "Supression des fichiers .o"
	@rm -f $(OBJ)
	@echo "\033[32m\t\t\t[OK]\033[0m"

fclean: clean
	@echo -n "Supression des executables"
	@rm -f lib/libft.a
	@rm -f lib/libmlx.a
	@rm -f $(NAME)
	@echo "\033[32m\t\t\t[OK]\033[0m"

re: fclean all

.PHONY:	all clean fclean re
