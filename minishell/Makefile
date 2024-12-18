# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 20:10:29 by analba-s          #+#    #+#              #
#    Updated: 2024/11/18 20:14:06 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PATH = lib/libft
LIBFT = -L$(LIBFT_PATH) -lft
SRCS_PATH = srcs
CC = clang
CFLAGS = -g -Wall -Werror -Wextra
OBJ_DIR = obj
DEPS = -I include -I $(LIBFT_PATH)
LIBS = $(LIBFT)

SOURCES = $(SRCS_PATH)/main.c $(SRCS_PATH/parse/parse.c) $(SRCS_PATH)/parse/tokens.c $(SRCS_PATH)/parse/join_tokens.c

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

all : head libft $(NAME)

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