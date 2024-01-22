NAME = libftprintf.a
AR = ar rcs
CC = gcc
CFLAS = -g -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putnbr_base.c ft_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "Library cretated"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Objects removed"

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "Library removed"

re: fclean all

.PHONY: all clean fclean re
