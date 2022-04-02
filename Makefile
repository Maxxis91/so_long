# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:52:53 by gmelissi          #+#    #+#              #
#    Updated: 2022/04/02 03:27:45 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	cc
SRC =	./mandatory/src/so_long.c ./mandatory/src/map.c \
		./mandatory/src/validation.c ./mandatory/src/error.c \
		./mandatory/src/loader.c ./mandatory/src/moves.c
BSRC =	./bonus/src/so_long_bonus.c ./bonus/src/map_bonus.c \
		./bonus/src/validation_bonus.c ./bonus/src/error_bonus.c \
		./bonus/src/loader_bonus.c ./bonus/src/moves_bonus.c
HDR =	./mandatory/include/so_long.h
BHDR =	./bonus/include/so_long_bonus.h
OBJ =	$(SRC:%.c=%.o)
BOBJ =	$(BSRC:%.c=%.o)
NAME =	so_long

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(HDR) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(GOBJ)
	make -C ./mlx
	cp ./mlx/libmlx.a ./
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./
	$(CC) $(OBJ) -Lmlx -lmlx -lz -Lft_printf -lftprintf -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

bonus: $(BOBJ)
	make -C ./mlx
	cp ./mlx/libmlx.a ./
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./
	$(CC) $(BOBJ) -Lmlx -lmlx -lz -Lft_printf -lftprintf -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)
	make clean -C ./mlx 
	make clean -C ./ft_printf
	
fclean: clean
	rm -f $(NAME)
	rm -f libmlx.a
	make fclean -C ./ft_printf
	rm -f libftprintf.a

re: fclean all
	
.PHONY:		all clean fclean re bonus