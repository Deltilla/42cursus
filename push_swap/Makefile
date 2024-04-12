# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2024/04/12 17:54:05 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
PS_PATH = srcs/push_swap
SRCS_PATH = srcs
BONUS_PATH = srcs/bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

PS_SOURCES = $(PS_PATH)/push_swap.c

SOURCES = $(SRCS_PATH)/parsing.c $(SRCS_PATH)/moves.c \
	$(SRCS_PATH)/move_utils.c $(SRCS_PATH)/sort_utils.c $(SRCS_PATH)/big_sort.c \
	$(SRCS_PATH)/math_utils.c $(SRCS_PATH)/init_list.c $(SRCS_PATH)/costs.c $(SRCS_PATH)/utils.c

BONUS_SOURCES = $(BONUS_PATH)/checker_bonus.c

OBJ_PS = $(PS_SOURCES:.c=.o)

OBJ = $(SOURCES:.c=.o)

OBJ_BONUS = $(BONUS_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_PS) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PS) $(OBJ) -L$(LIBFT_PATH) -lft
	@echo "Archivo creado"

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)

bonus : $(LIBFT) $(OBJ_BONUS) $(OBJ)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_BONUS) $(OBJ) -L$(LIBFT_PATH) -lft

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rm -f $(OBJ_PS)
	@rm -f $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) clean_libft
	@echo "Limpieza realizada"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@$(MAKE) -C $(LIBFT_PATH) fclean_libft
	@echo "Limpieza profunda realizada"

re : fclean all bonus

.PHONY: all clean fclean re bonus
