#incldue "libftprintf.h"
#incldue <stdarg.h>

void    ft_isint(va_list args, int ctrl)
{
    int r;

    r = va_arg(args, int);
    if (ctrl == 1)
        ft_putnbr_base(r, "0123456789");
    if (ctrl == 2)
        ft_putnbr_base(r, "");
    if (ctrl == 3)
    {
        if (r < 0)
            r *= -1;
        ft_putnbr_base(r, "0123456789");
    }
    if (ctrl == 4)
        ft_putnbr_base(r, "0123456789abcdef");
    if (ctrl == 5)
        ft_putnbr_base(r, "0123456789ABCDEF");
}