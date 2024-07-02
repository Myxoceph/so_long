# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:07:10 by abakirca          #+#    #+#              #
#    Updated: 2024/05/27 15:12:21 by abakirca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long
LIBFT				= ./libft/libft.a
MINILIBX			= ./mlx/libmlx.a
GNL					= ./get_next_line/
SRC_DIR				= srcs/
OBJ_DIR				= obj/
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

SO_LONG_DIR			= $(SRC_DIR)main.c $(GNL)get_next_line.c $(GNL)get_next_line_utils.c $(SRC_DIR)so_long_utils.c \
					  $(SRC_DIR)so_long_controls1.c $(SRC_DIR)so_long_controls2.c $(SRC_DIR)so_long_controls3.c \
					  $(SRC_DIR)image_print.c $(SRC_DIR)keys.c \

SRCS 				= $(SO_LONG_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT) $(MINILIBX)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
					@make -C ./libft

$(MINILIBX):
					@make -C ./mlx

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) -Imlx $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
					@make clean -C ./mlx

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			all clean fclean re
