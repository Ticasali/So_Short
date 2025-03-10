# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 09:27:00 by ticasali          #+#    #+#              #
#    Updated: 2025/02/17 12:35:28 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Elaym

SRC		=	src/main.c		\

OBJ		:=	$(SRC:%.c=%.o)

CC	=	cc

CCFLAGS	= -Wextra -Wall -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	make clean -C mlx_linux/
	rm -f $(NAME)

re :	fclean all