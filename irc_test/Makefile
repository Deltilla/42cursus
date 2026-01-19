CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I includes

NAME = ircserv
MINI = mini_irc_test

SRCS = srcs/Server.cpp srcs/Client.cpp srcs/Channel.cpp
MAIN = srcs/main.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN_OBJ = $(MAIN:.cpp=.o)

all: $(NAME) $(MINI)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(MINI): mini_irc_test.cpp
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME) $(MINI)

re: fclean all

.PHONY: all clean fclean re
