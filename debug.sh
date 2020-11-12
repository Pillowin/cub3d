#! /bin/zsh

gcc -Iheader -Llib -Wall -Werror -Wextra -g src/*.c -lft -lmlx -lXext -lX11
