# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2024/06/09 17:41:08 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MAIN_PATH = srcs
SRCS_PATH = srcs
CC = clang
CFLAGS = -g -Wall -Werror -Wextra
DEPS = -I includes

MAIN_SOURCES = $(MAIN_PATH)/so_long.c $(MAIN_PATH)/parse_map.c $(MAIN_PATH)/parse_utils.c

SOURCES = $(SRCS_PATH)/utils.c

MAIN_OBJ = $(MAIN_SOURCES:.c=.o)

OBJ = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(MAIN_OBJ) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) -L$(LIBFT_PATH) -lft
	@echo "Archivo creado"

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)


%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPS)

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
