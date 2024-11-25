# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:00:38 by lgottsch          #+#    #+#              #
#    Updated: 2024/11/25 16:36:55 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TO DO 
#default make => linux
#make rule for mac

NAME = fdf

LIBFTDIR= ./full_libft
MLXDIR= ./mlx_linux

CC = cc 
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS_LX = -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lm
MLX_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC= try_parse.c
OBJ = $(SRC:.c=.o)

AFILES= full_libft/full_libft.a \
	mlx_linux/libmlx_Linux.a \
		

$(NAME): libft mlx
	$(CC) $(CFLAGS) $(SRC) $(AFILES) -o $(NAME) $(MLX_FLAGS_LX)

libft:
	@make -C full_libft

mlx: 
	cd mlx_linux && ./configure

all: $(NAME)

clean:
	rm -f $(OBJ)
	@cd $(LIBFTDIR) && make clean
	@cd $(MLXDIR) && make clean

fclean: clean
	rm -f $(NAME)
	@cd $(LIBFTDIR) && make clean
	@cd $(MLXDIR) && make clean

re: fclean all

#compilation on mac
mac: libft mlx
	$(CC) $(CFLAGS) $(SRC) $(AFILES) -o $(NAME) $(MLX_FLAGS_MAC)


.PHONY: all clean fclean re libft mlx mac