NAME = libft.a
FT_PRINTF_PATH = ft_printf
GNL_PATH = gnl
CC = clang
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

LIB_SRCS = ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_calloc.c \
ft_atoi.c ft_isalnum.c ft_isdigit.c	ft_memcmp.c	ft_memset.c	ft_strlcat.c ft_strncmp.c ft_tolower.c \
ft_bzero.c ft_isalpha.c	ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_toupper.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LIB_BSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c

FT_PRINTF_SRCS = $(FT_PRINTF_PATH)/ft_printf.c $(FT_PRINTF_PATH)/ft_utils.c \
$(FT_PRINTF_PATH)/ft_putnbr_base.c

GNL_SRCS = $(GNL_PATH)/get_next_line_bonus.c $(GNL_PATH)/get_next_line_utils_bonus.c

LIB_OBJ = $(LIB_SRCS:.c=.o)
LIB_BOBJ = $(LIB_BSRCS:.c=.o)
FT_PRINTF_OBJ = $(FT_PRINTF_SRCS:.c=.o)
GNL_OBJ = $(GNL_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIB_OBJ) $(LIB_BOBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ)
	@$(AR) $(NAME) $(LIB_OBJ) $(LIB_BOBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ)

bonus : $(LIB_BOBJ)
	@$(AR) $(NAME) $(LIB_BOBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean_libft :
	@rm -f $(LIB_OBJ) $(LIB_BOBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ)

fclean_libft : clean_libft
	@rm -f $(NAME)

re : fclean_libft all
.PHONY: all bonus clean fclean re
