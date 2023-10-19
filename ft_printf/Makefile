NAME = libftprintf.a
AR = ar rcs
CC = gcc
CFLASG = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putnbr_base.c ft_isint.c ft_ischar.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft all bonus
	@mv libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "Printf objects"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
