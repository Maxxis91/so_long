# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:52:53 by gmelissi          #+#    #+#              #
#    Updated: 2022/03/29 21:57:51 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	cc
SRC =	so_long.c map.c validation.c error.c loader.c moves.c\
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c
HDR =	so_long.h
OBJ =	$(SRC:%.c=%.o)
NAME =	so_long

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(HDR) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C ./mlx
	cp ./mlx/libmlx.a ./
	$(CC) $(OBJ) -Lmlx -lmlx -lz -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C mlx 
	
fclean: clean
	rm -f $(NAME)
	rm -f libmlx.a

re: fclean all
	
.PHONY:		all clean fclean re bonus