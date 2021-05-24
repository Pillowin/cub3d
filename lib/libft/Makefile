# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:52:43 by agautier          #+#    #+#              #
#    Updated: 2021/01/30 16:15:40 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	src/ft_atoi_base.c \
			src/ft_atoi.c \
			src/ft_bzero.c \
			src/ft_calloc.c \
			src/ft_div_mod.c \
			src/ft_fibonacci.c \
			src/ft_find_next_prime.c \
			src/ft_free.c \
			src/ft_get_whitespaces.c \
			src/ft_ilen.c \
			src/ft_isalnum.c \
			src/ft_isalpha.c \
			src/ft_isascii.c \
			src/ft_isdigit.c \
			src/ft_islower.c \
			src/ft_is_prime.c \
			src/ft_isprint.c \
			src/ft_isupper.c \
			src/ft_itoa.c \
			src/ft_latoi.c \
			src/ft_lstadd_back.c \
			src/ft_lstadd_front.c \
			src/ft_lstclear.c \
			src/ft_lstdelone.c \
			src/ft_lstiter.c \
			src/ft_lstlast.c \
			src/ft_lstmap.c \
			src/ft_lstnew.c \
			src/ft_lstsize.c \
			src/ft_memccpy.c \
			src/ft_memchr.c \
			src/ft_memcmp.c \
			src/ft_memcpy.c \
			src/ft_memmove.c \
			src/ft_memset.c \
			src/ft_putchar.c \
			src/ft_putchar_fd.c \
			src/ft_putendl_fd.c \
			src/ft_putlnbr.c \
			src/ft_putlstr.c \
			src/ft_putnbr_base.c \
			src/ft_putnbr.c \
			src/ft_putnbr_fd.c \
			src/ft_putstr.c \
			src/ft_putstr_fd.c \
			src/ft_putstr_non_printable.c \
			src/ft_putulnbr_base.c \
			src/ft_putunbr_base.c \
			src/ft_range.c \
			src/ft_recursive_factorial.c \
			src/ft_recursive_power.c \
			src/ft_rev_int_tab.c \
			src/ft_sort_int_tab.c \
			src/ft_split.c \
			src/ft_split_charset.c \
			src/ft_sqrt.c \
			src/ft_strcapitalize.c \
			src/ft_strcat.c \
			src/ft_strchr.c \
			src/ft_strcmp.c \
			src/ft_strcpy.c \
			src/ft_strdup.c \
			src/ft_str_is_alpha.c \
			src/ft_str_is_lowercase.c \
			src/ft_str_is_numeric.c \
			src/ft_str_is_printable.c \
			src/ft_str_is_uppercase.c \
			src/ft_strjoin.c \
			src/ft_strlcat.c \
			src/ft_strlchr.c \
			src/ft_strlcpy.c \
			src/ft_strlen.c \
			src/ft_strlowcase.c \
			src/ft_strmapi.c \
			src/ft_strncat.c \
			src/ft_strncmp.c \
			src/ft_strncpy.c \
			src/ft_strnstr.c \
			src/ft_strrchr.c \
			src/ft_strstr.c \
			src/ft_strtrim.c \
			src/ft_strupcase.c \
			src/ft_substr.c \
			src/ft_swap.c \
			src/ft_tolower.c \
			src/ft_toupper.c \
			src/ft_ultimate_div_mod.c \
			src/ft_ultimate_range.c \
			src/get_next_line.c
OBJ		=	$(SRC:.c=.o)
HEADER	=	header
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar	rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
