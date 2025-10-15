# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2025/10/15 19:12:31 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
SRCS_PATH = srcs
CC = c++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98
OBJ_DIR = obj
DEPS = -I includes

SOURCES = srcs/main.cpp \
		srcs/Bureaucrat.cpp \
		srcs/Intern.cpp \
		srcs/AForm.cpp \
		srcs/ShrubberyCreationForm.cpp \
		srcs/RobotomyRequestForm.cpp \
		srcs/PresidentialPardonForm.cpp
		

OBJ = $(SOURCES:$(SRCS_PATH)/%.cpp=$(OBJ_DIR)/%.o)
OBJ_TEST = $(SOURCES_TEST:$(SRCS_PATH)/%.cpp=$(OBJ_DIR)/%.o)


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
	@echo "\tProyect: \033[36m cpp_ex03 $(BLUE)"
	@echo "\tCommands:\033[36m all test clean fclean re $(WHITE)\n"


$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled successfully! ✓ $(WHITE)"

$(NAME_TEST) : $(OBJ_TEST)
	@$(CC) -o $(NAME_TEST) $(OBJ_TEST)
	@echo "$(GREEN)$(NAME_TEST) compiled successfully! ✓ $(WHITE)"

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPS)
	@echo "  ✓ Compiled: $(notdir $<)"

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Clean  ✓ $(WHITE)"

fclean :
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME) $(NAME_TEST)
	@rm -f *_shrubbery
	@echo "$(GREEN)Hardly clean  ✓ $(WHITE)"

re : fclean all

.PHONY: all test clean fclean re
