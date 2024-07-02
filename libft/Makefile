# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 16:24:56 by abakirca          #+#    #+#              #
#    Updated: 2024/05/08 14:06:23 by abakirca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -rf
AR					= ar rcs

LIBFT_DIR			=	$(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_bzero.c $(SRC_DIR)ft_calloc.c $(SRC_DIR)ft_isalnum.c $(SRC_DIR)ft_isalpha.c \
						$(SRC_DIR)ft_isascii.c $(SRC_DIR)ft_isdigit.c $(SRC_DIR)ft_isprint.c $(SRC_DIR)ft_itoa.c $(SRC_DIR)ft_memchr.c \
						$(SRC_DIR)ft_memcmp.c $(SRC_DIR)ft_memcpy.c $(SRC_DIR)ft_memmove.c $(SRC_DIR)ft_memset.c $(SRC_DIR)ft_putchar_fd.c \
						$(SRC_DIR)ft_putendl_fd.c $(SRC_DIR)ft_putnbr_fd.c $(SRC_DIR)ft_putstr_fd.c $(SRC_DIR)ft_split.c $(SRC_DIR)ft_strchr.c \
						$(SRC_DIR)ft_strdup.c $(SRC_DIR)ft_striteri.c $(SRC_DIR)ft_strjoin.c $(SRC_DIR)ft_strlcat.c $(SRC_DIR)ft_strlcpy.c \
						$(SRC_DIR)ft_strlen.c $(SRC_DIR)ft_strmapi.c $(SRC_DIR)ft_strncmp.c $(SRC_DIR)ft_strnstr.c $(SRC_DIR)ft_strrchr.c \
						$(SRC_DIR)ft_strtrim.c $(SRC_DIR)ft_substr.c $(SRC_DIR)ft_tolower.c $(SRC_DIR)ft_toupper.c $(SRC_DIR)ft_hex.c \
						$(SRC_DIR)ft_putnbrs.c $(SRC_DIR)ft_putchars.c $(SRC_DIR)ft_printf.c $(SRC_DIR)ft_printf_utils.c \
						$(SRC_DIR)ft_lstadd_back_bonus.c $(SRC_DIR)ft_lstadd_front_bonus.c $(SRC_DIR)ft_lstclear_bonus.c \
						$(SRC_DIR)ft_lstdelone_bonus.c $(SRC_DIR)ft_lstiter_bonus.c $(SRC_DIR)ft_lstlast_bonus.c \
						$(SRC_DIR)ft_lstnew_bonus.c $(SRC_DIR)ft_lstsize_bonus.c

SRC 				= $(LIBFT_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))


all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@$(RM) $(OBJ_DIR)

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
