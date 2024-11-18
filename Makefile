# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:00:38 by lgottsch          #+#    #+#              #
#    Updated: 2024/11/18 16:04:23 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TO DO 
# include minilibx somehow

NAME = fdf

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = fdf.c \
		full_libft/full_libft.a

OBJ = $(SRC:.c=.o)
LIBFTDIR= ./full_libft

$(NAME): 
	@make -C full_libft
	$(CC) $(CFLAGS) $(SRC) -o fdf 

all: $(NAME)

clean:
	rm -f $(OBJ)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	@cd $(LIBFTDIR) && make clean

re: fclean all 

.PHONY: all clean fclean re