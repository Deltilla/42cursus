//#include "libftprtinf.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_check_format(void *f, va_list args)
{
	if (*f == c)
		ft_ischar(args, 1); // ischar tendra una variable r que utilizara va_arg para convertirse en la necesaria segun una variable control.
	if (*f == 'p')
		ft_ischar(args, 2);
	if (*f == 's')
		ft_ischar(args, 3);
	if (*f == 'd')
		ft_isint(args); //base decimal
	if (*f == 'i')
		ft_isint(args) //base decimal, octal o hexadecimal
	if (*f == 'u')
		ft_isint(args); //base decimal sin signo
	if (*f == 'x')
		ft_isint(args); //base hexadecimal en minusculas
	if (*f == 'X')
		ft_isint(args); //base hexadecimal en mayusculas
}

int ft_printf(const char *f, ...)
{
	int		r; //Puedo ahorrarme declarar una variable de cada tipo?
	int		*p;
	char	*s;
	const char	*f1;
	va_list	args;

	va_start(args, f);
	while (*f != '\0' && f1 != '\0')
	{
		f1 = f + 1;
		if (*f == '%' && ft_strchr("cpsdiuxX", *f1) != 0)
		{
			ft_chek_format(f1, args); //Considerar donde hacer va_arg
			f += 2;
		}
		else
		{
			ft_putchar_fd(1, *f);
			f++;
		}
	}
	va_end(args);
	return (f);
}

int main (void)
{
	int num = 42;
	char *s = "Hola wenas";
	int chars = ft_printf("Numero: %d, String: %s\n", num, s);

	printf("Numero de caracteres impresos: %s\n", chars);
}