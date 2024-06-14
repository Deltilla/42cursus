# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2024/06/14 16:04:28 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx42
LIBFT = -L$(LIBFT_PATH) -lft
MLX42 = $(MLX_PATH)/build/libmlx42.a
LIBGL = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
SRCS_PATH = srcs
CC = clang
CFLAGS = -g -Wall -Werror -Wextra
OBJ_DIR = obj
DEPS = -I include -I $(LIBFT_PATH) -I $(MLX_PATH)/include
LIBS = $(LIBGL) $(MLX42) $(LIBFT)

SOURCES = $(SRCS_PATH)/so_long.c $(SRCS_PATH)/parse/parse_map.c $(SRCS_PATH)/parse/parse_utils.c $(SRCS_PATH)/utils/utils.c \
			$(SRCS_PATH)/game/animation.c $(SRCS_PATH)/game/fill_map.c $(SRCS_PATH)/game/images.c $(SRCS_PATH)/game/load_map.c \
			$(SRCS_PATH)/game/load_player.c $(SRCS_PATH)/game/load_soldier.c $(SRCS_PATH)/game/mlx_calling.c $(SRCS_PATH)/game/move_player.c

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

all : head mlx42 libft $(NAME)

head:
	@echo "$(BLUE)"
	@echo "\t                                                                               "
	@echo "\t      ::::::::   ::::::::            :::        ::::::::  ::::    :::  :::::::: " 
	@echo "\t    :+:    :+: :+:    :+:           :+:       :+:    :+: :+:+:   :+: :+:    :+:" 
	@echo "\t   +:+        +:+    +:+           +:+       +:+    +:+ :+:+:+  +:+ +:+        " 
	@echo "\t  +#++:++#++ +#+    +:+           +#+       +#+    +:+ +#+ +:+ +#+ :#:         " 
	@echo "\t        +#+ +#+    +#+           +#+       +#+    +#+ +#+  +#+#+# +#+   +#+#   " 
	@echo "\t#+#    #+# #+#    #+#           #+#       #+#    #+# #+#   #+#+# #+#    #+#    " 
	@echo "\t########   ######## ########## ########## ########  ###    ####  ########" 
	@echo "\t        By analba-s"
	@echo "\tProyect: \033[36m so_long $(BLUE)"
	@echo "\tCommands:\033[36m all clean fclean re $(WHITE)\n"

libft :
	@$(MAKE) -s -C $(LIBFT_PATH)

mlx42 :
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build && make -s -C $(MLX_PATH)/build -j4

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPS)
	@echo "  ✓ Compiled: $(notdir $<)"

clean :
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_PATH) clean_libft
	@echo "$(GREEN)Clean  ✓ $(WHITE)"

fclean :
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_PATH) fclean_libft
	@echo "$(GREEN)Hardly clean  ✓ $(WHITE)"

re : fclean all

.PHONY: all clean fclean re
