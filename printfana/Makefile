NAME = libftprintf.a
AR = ar rcs
CC = gcc
CFLASG = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putnbr_base.c ft_isint.c ft_ischar.c ft_ispointer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "Printf objects"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
