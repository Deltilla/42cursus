NAME = pushswap.a
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SOURCES = prueba.c create_list.c

OBJ = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@$(AR) $(NAME) $(LIBFT_PATH)/*.o $(OBJ)
	@echo "Archivos creados"

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean_libft
	@echo "Limpieza realizada"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean_libft
	@echo "Limpieza profunda realizada"

re : fclean all

.PHONY: all clean fclean re
