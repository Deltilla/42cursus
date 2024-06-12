# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2024/06/12 19:54:54 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx42
LIBFT = $(LIBFT_PATH)/libft.a
SRCS_PATH = srcs
CC = clang
CFLAGS = -g -Wall -Werror -Wextra
OBJ_DIR = obj
DEPS = -I include -I $(LIBFT_PATH) -I $(MLX_PATH)/include

SOURCES = $(SRCS_PATH)/so_long.c $(SRCS_PATH)/parse_map.c $(SRCS_PATH)/parse_utils.c $(SRCS_PATH)/utils.c
	$(SRCS_PATH)/animation.c $(SRCS_PATH)/fill_map.c $(SRCS_PATH)/images.c $(SRCS_PATH)/load_map.c
	$(SRCS_PATH)/load_player.c $(SRCS_PATH)/load_soldier.c $(SRCS_PATH)/mlx_calling.c $(SRCS_PATH)/move_player.c
	
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))


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

all : head $(NAME)

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

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft

$(LIBFT) :
	@$(MAKE) -s -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
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
