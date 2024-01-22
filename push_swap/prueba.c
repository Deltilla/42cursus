#include "libft/libft.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr_fd("No hay argumentos\n", 1);
	else
		ft_putstr_fd(argv[1], 1);
}
