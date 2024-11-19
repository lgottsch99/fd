# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:00:38 by lgottsch          #+#    #+#              #
#    Updated: 2024/11/19 19:28:52 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TO DO 
# include minilibx somehow

NAME = fdf

LIBFTDIR= ./full_libft
MLXDIR= ./minilibx-linux
OBJDIR= 

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = fdf.c \



		full_libft/full_libft.a \
		minilibx-linux/libmlx_Linux.a \

MLX_FLAGS_LINUX = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_FLAGS_MAC =	-lm -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit

$(NAME): 
	@make -C full_libft
	cd minilibx-linux && ./configure
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS_LINUX) -o fdf

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

.PHONY: all clean fclean re