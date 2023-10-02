NAME = libftprintf
AR = ar rcs
CC = gcc
CFLASG = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putnbr_base_mod.c ft_isint.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft 

libft/libft.a:
	make -C libft all bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
