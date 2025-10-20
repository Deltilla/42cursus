# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2025/10/20 12:08:03 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = template
SRCS_PATH = srcs
CC = c++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98
OBJ_DIR = obj
DEPS = -I includes

SOURCES = srcs/main.cpp
		

OBJ = $(SOURCES:$(SRCS_PATH)/%.cpp=$(OBJ_DIR)/%.o)


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

head :
	@echo "$(BLUE)"
	@echo "\t                                           "
	@echo "\t            								"
	@echo "\t						▛▘▛▌▛▌				"
	@echo "\t						▙▖▙▌▙▌				"
	@echo "\t						  ▌ ▌ 				" 
	@echo "\t        By analba-s"
	@echo "\tProyect: \033[36m cpp_ex00 $(BLUE)"
	@echo "\tCommands:\033[36m all clean fclean re $(WHITE)\n"


$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPS)
	@echo "  ✓ Compiled: $(notdir $<)"

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Clean  ✓ $(WHITE)"

fclean :
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "$(GREEN)Hardly clean  ✓ $(WHITE)"

re : fclean all

.PHONY: all clean fclean re
