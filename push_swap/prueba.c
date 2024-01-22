#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	ti_list	*list;
	int		i;
	if (argc == 1)
		ft_putstr_fd("Error\n", 2);
	else
		list = create_list(argc, argv);
	i = 0;
	while (i < argc)
	{
		printf("%d\n", list->content);
		list = list->next;
		i++;
	}
}
