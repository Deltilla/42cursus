#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct  i_list
{
    int				content;
    struct i_list   *next;
    struct i_list	*prev;
}               ti_list;

ti_list    *create_list(int c, char **list);

#endif