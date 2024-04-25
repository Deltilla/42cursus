# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2024/04/22 19:05:26 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MAIN_PATH = srcs/pipex
SRCS_PATH = srcs
BONUS_PATH = srcs/pipex_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

MAIN_SOURCES = $(MAIN_PATH)/pipex.c

SOURCES = $(SRCS_PATH)/prueba.c

BONUS_SOURCES = $(BONUS_PATH)/pipex_bonus.c

MAIN_OBJ = $(MAIN_SOURCES:.c=.o)

OBJ = $(SOURCES:.c=.o)

BONUS_OBJ = $(BONUS_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(MAIN_OBJ) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) -L$(LIBFT_PATH) -lft
	@echo "Archivo creado"

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)

bonus : $(LIBFT) $(BONUS_OBJ) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ) $(OBJ) -L$(LIBFT_PATH) -lft

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rm -f $(MAIN_OBJ)
	@rm -f $(BONUS_OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean_libft
	@echo "Limpieza realizada"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean_libft
	@echo "Limpieza profunda realizada"

re : fclean all bonus

.PHONY: all clean fclean re bonus
