# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 20:39:27 by ticasali          #+#    #+#              #
#    Updated: 2024/11/01 02:18:02 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Elaym

SRC		=	src/main.c		\
			src/load.c		\
			src/tools.c		\
			src/tool2.c 	\
			src/event.c		\
			src/move.c		\
			src/image.c

OBJ		:=	$(SRC:%.c=%.o)

CC	=	gcc

CCFLAGS	= -Wextra -Wall

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