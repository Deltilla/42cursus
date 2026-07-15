NAME = Inception
SRCS_PATH = srcs
COMPOSE_FILE = $(SRCS_PATH)/docker-compose.yml
LOGIN = analba-s
DATA_PATH = /home/$(LOGIN)/data

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

all : head up 

head :
	@echo "$(BLUE)"
	@echo "\t                                           "
	@echo "\t                                           "
	@echo "\t\t			▄▖        ▗ ▘    				"
	@echo "\t\t			▐ ▛▌▛▘█▌▛▌▜▘▌▛▌▛▌				"
	@echo "\t\t			▟▖▌▌▙▖▙▖▙▌▐▖▌▙▌▌▌				"
	@echo "\t\t			        ▌        				"			
	@echo "\t   By $(LOGIN)"
	@echo "\tProject: \033[36m $(NAME) $(BLUE)"
	@echo "\tCommands:\033[36m all up down clean fclean re $(WHITE)\n"

up :
	@echo "$(YELLOW) Preparing host directories for volumes...$(WHITE)"
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	@echo "$(GREEN) Directories ready! ✓ $(WHITE)"
	@echo "$(YELLOW) Checking /etc/hosts for domain...$(WHITE)"

	@if ! grep -q "$$DOMAIN_NAME" /etc/hosts; then \
		echo "$(YELLOW)Adding $$DOMAIN_NAME to /etc/hosts...$(WHITE)"; \
		echo "127.0.0.1 $$DOMAIN_NAME" | sudo tee -a /etc/hosts > /dev/null; \
	else \
		echo "$(GREEN)Domain $$DOMAIN_NAME already exists in /etc/hosts. ✓$(WHITE)"; \
	fi
	@echo "$(YELLOW) Building and starting Docker containers...$(WHITE)"
	@docker compose -f $(COMPOSE_FILE) up --build -d
	@echo "$(GREEN) $(NAME) is up and running! ✓ $(WHITE)"

down :
	@echo "$(RED) Stopping containers...$(WHITE)"
	@docker compose -f $(COMPOSE_FILE) down
	@echo "$(GREEN) Containers stopped. ✓ $(WHITE)"

clean :
	@echo "$(RED) Cleaning up containers and networks...$(WHITE)"
	@docker compose -f $(COMPOSE_FILE) down --rmi all -v
	@echo "$(GREEN) Clean  ✓ $(WHITE)"

fclean : clean
	@echo "$(RED) Purging data volumes from host ($(DATA_PATH))...$(WHITE)"
	@if [ -n "$$(docker ps -aq)" ]; then docker stop $$(docker ps -aq); fi
	@docker system prune --all --volumes --force
	@docker network prune --force
	@docker volume prune --force
	@docker image prune --force --all
	@docker builder prune --force --all
	@if [ -n "$$(docker volume ls -q)" ]; then docker volume rm $$(docker volume ls -q); fi
	@if [ -d "$(DATA_PATH)" ]; then sudo rm -rf $(DATA_PATH); fi
	@echo "$(GREEN) Hardly clean  ✓ $(WHITE)"

re : fclean all

.PHONY: all head up down clean fclean re