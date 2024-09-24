# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:19:06 by analba-sa         #+#    #+#              #
#    Updated: 2024/09/23 19:04:55 by analba-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS_PATH = srcs
CC = clang
CFLAGS = -g -Wall -Werror -Wextra
OBJ_DIR = obj
DEPS = -I includes

SOURCES = $(SRCS_PATH)/philo.c $(SRCS_PATH)/parse.c \
		$(SRCS_PATH)/threads.c $(SRCS_PATH)/philo_actions.c $(SRCS_PATH)/observer.c \
		$(SRCS_PATH)/utils.c

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

all : head $(NAME)

head:
	@echo "$(BLUE)"
	@echo "\t                                                                               "
	@echo "\t      :::::::::  :::    ::: ::::::::::: :::        ::::::::   ::::::::   ::::::::  :::::::::  :::::::::: :::::::::   :::::::: " 
	@echo "\t     :+:    :+: :+:    :+:     :+:     :+:       :+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:        :+:    :+: :+:    :+: " 
	@echo "\t    +:+    +:+ +:+    +:+     +:+     +:+       +:+    +:+ +:+        +:+    +:+ +:+    +:+ +:+        +:+    +:+ +:+         " 
	@echo "\t   +#++:++#+  +#++:++#++     +#+     +#+       +#+    +:+ +#++:++#++ +#+    +:+ +#++:++#+  +#++:++#   +#++:++#:  +#++:++#++   " 
	@echo "\t  +#+        +#+    +#+     +#+     +#+       +#+    +#+        +#+ +#+    +#+ +#+        +#+        +#+    +#+        +#+    " 
	@echo "\t #+#        #+#    #+#     #+#     #+#       #+#    #+# #+#    #+# #+#    #+# #+#        #+#        #+#    #+# #+#    #+#     " 
	@echo "\t###        ###    ### ########### ########## ########   ########   ########  ###        ########## ###    ###  ########       " 
	@echo "\t        By analba-s"
	@echo "\tProyect: \033[36m so_long $(BLUE)"
	@echo "\tCommands:\033[36m all clean fclean re $(WHITE)\n"


$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.c
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
