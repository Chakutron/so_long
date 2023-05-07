# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 15:15:55 by mchiboub          #+#    #+#              #
#    Updated: 2023/05/02 15:23:07 by mchiboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PRINTF = printf
PRINTF_LIB = libftprintf.a

GNL = gnl

MLX = mlx
MLX_LIB = libmlx.a

SRCS =	so_long.c					\
		check_map.c					\
		enemy_move.c				\
		ft_itoa.c					\
		handle_events.c				\
		image_utils.c				\
		init_game.c					\
		load_image.c				\
		load_map.c					\
		render.c					\
		show_interface.c			\
		show_map.c					\
		titles.c					\
		update_player.c				\
		work_animations.c			\
		${GNL}/get_next_line.c		\
		${GNL}/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

GREEN = \033[0;32m
NC = \033[0m

all: ${NAME}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -Lmlx -lmlx -Imlx -lX11 -lXext

${NAME}: ${OBJS}
		@echo "Generating ${GREEN}${NAME}${NC} executable.."
		@make -sC ${PRINTF} all
		@${CC} -o ${NAME} ${OBJS} ${PRINTF}/${PRINTF_LIB} ${MLX}/${MLX_LIB} -Lmlx -lmlx -Imlx -lX11 -lXext

clean:
		@echo "Deleting object files.."
		@rm -f ${OBJS}
		@make -sC ${PRINTF} clean

fclean: clean
		@echo "Deleting object & executable files.."
		@rm -f ${NAME}
		@make -sC ${PRINTF} fclean

re: fclean all
