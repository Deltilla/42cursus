#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2024/05/29 12:25:49 by analba-s         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pipex
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MAIN_PATH = srcs
SRCS_PATH = srcs
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
AR = ar rcs

MAIN_SOURCES = $(MAIN_PATH)/pipex.c

SOURCES = $(SRCS_PATH)/utils.c $(SRCS_PATH)/exeguttor.c

MAIN_OBJ = $(MAIN_SOURCES:.c=.o)

OBJ = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(MAIN_OBJ) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) -L$(LIBFT_PATH) -lft
	@echo "Archivo creado"

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)


%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rm -f $(MAIN_OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean_libft
	@echo "Limpieza realizada"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean_libft
	@echo "Limpieza profunda realizada"

re : fclean all

.PHONY: all clean fclean re
