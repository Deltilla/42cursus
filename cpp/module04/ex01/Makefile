# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2025/10/05 15:32:06 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals
SRCS_PATH = srcs
CC = c++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98
OBJ_DIR = obj
DEPS = -I includes

SOURCES = srcs/main.cpp \
		srcs/Animal.cpp \
		srcs/Cat.cpp \
		srcs/Dog.cpp \
		srcs/Brain.cpp
		

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

all : $(NAME)


$(NAME) : $(OBJ)
	@echo "$(BLUE)"
	@echo "\t                                           "
	@echo "\t            \t\t                        "
	@echo "\t▛▘▛▌▛▌\t\t\t"
	@echo "\t▙▖▙▌▙▌\t\t\t"
	@echo "\t  ▌ ▌ \t\t\t" 
	@echo "\t        By analba-s"
	@echo "\tProyect: \033[36m cpp_ex00 $(BLUE)"
	@echo "\tCommands:\033[36m all clean fclean re $(WHITE)\n"
	@$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPS)
	@echo "$(notdir $<): $(GREEN)✓ Compiled$(WHITE)"

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Clean  ✓ $(WHITE)"

fclean :
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "$(GREEN)Fclean done  ✓ $(WHITE)"

re : fclean all

.PHONY: all clean fclean re
