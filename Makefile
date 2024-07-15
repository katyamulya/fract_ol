# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 11:46:47 by kdvarako          #+#    #+#              #
#    Updated: 2024/07/12 15:50:36 by kdvarako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_1 = fractol.c
SRC_2 = $(wildcard utils/*.c)

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

CC = cc

CFlAGS = -Wall -Wextra -Werror
MLXFLAGS = -L./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

LIBFT = ./libft/libft.a

MLX = ./mlx

all:	${NAME}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(LIBFT):
	$(MAKE) -C ./libft

$(MLX):
	$(MAKE) -C ./mlx

${NAME}:	${OBJ_1} ${OBJ_2} ${LIBFT} ${MLX}
	${CC} ${CFlAGS} ${OBJ_1} ${OBJ_2} ${MLXFLAGS} -o ${NAME}

clean:
	rm -f ${OBJ_1} ${OBJ_2}
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx

fclean:	clean
	rm -f ${NAME}
	$(MAKE) fclean -C ./libft

re:	fclean all

.PHONY: all clean fclean re ${LIBFT} ${MLX}