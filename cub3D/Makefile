# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2025/07/08 12:37:38 by frmarian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT_PATH = libs/libft
MLX_PATH = libs/mlx
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11
SRCS_PATH = srcs
CC = clang
CFLAGS = -g -Wall -Werror -Wextra
OBJ_DIR = obj
DEPS = -Iinclude -I$(LIBFT_PATH) -I$(MLX_PATH)
LIBS = $(LIBFT) $(MLX_FLAGS)

SOURCES = $(SRCS_PATH)/cub3D.c

OBJ = $(SOURCES:$(SRCS_PATH)/%.c=$(OBJ_DIR)/%.o)

################################################################################
##                                    COLOURS                                 ##
################################################################################

WHITE=\033[0m
BOLD=\033[1m
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[33m
MAGENTA=\033[35m
TURQUOISE=\033[36m

################################################################################
##                                    RULES                                   ##
################################################################################

all : head libft mlx $(NAME)

head:
	@echo "$(BLUE)"
	@echo "\t                                                                               "
	@echo "\t      ▌  ▄▖▄ "
	@echo "\t  ▛▘▌▌▛▌ ▄▌▌▌"
	@echo "\t  ▙▖▙▌▙▌ ▄▌▙▘"
	@echo "\t        By analba-s" 
	@echo "\tProyect: \033[36m cub3D $(BLUE)"
	@echo "\tCommands:\033[36m all clean fclean re $(WHITE)\n"

libft :
	@$(MAKE) -s -C $(LIBFT_PATH) > /dev/null 2>&1

mlx :
	@$(MAKE) -s -C $(MLX_PATH) > /dev/null 2>&1

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!\n$(WHITE)"

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPS)

clean :
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_PATH) clean_libft > /dev/null 2>&1
	@$(MAKE) -s -C $(MLX_PATH)  clean > /dev/null 2>&1
	@echo "🧹 $(GREEN)Object files removed\n$(WHITE)"

fclean :
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_PATH) fclean_libft > /dev/null 2>&1
	@echo "🗑️  $(GREEN)$(NAME) removed\n$(WHITE)"

re : fclean all

.PHONY: all clean fclean re