#include "ft_printf.h"

static void    print_space(int *val, t_args *tab, int max)
{
    int i;

    i = 0;
    while (i++ < max)
        ft_putchar_fd(' ', 1);
    tab->tl += i;
}

static void    print_zero(int *val, t_args *tab, int max)
{
    int i;

    i = 0;
    while (i++ < max)
        ft_putchar_fd('0', 1);
    tab->tl += i;
}

static void    handling_width_and_precision(t_args *tab, int *val)
{
    if (tab->wdt > tab->prc)
    {
        if (tab->dash)
        {
            print_zero(val, tab, tab->prc - ft_counter_number(*val));
            ft_putnbr_fd(*val, 1);
            print_space(val, tab, tab->wdt - tab->prc);
        }
        else
        {
            print_space(val, tab, tab->wdt - tab->prc);
            print_zero(val, tab, tab->prc - ft_counter_number(*val));
        }
    }
    else
        print_zero(val, tab, tab->prc - ft_counter_number(*val));
}


static void    handling_precision(t_args *tab, int *val)
{
    print_zero(val, tab, tab->prc - ft_counter_number(*val));
}

static void    handling_width(t_args *tab, int *val)
{
    if (tab->zero)
        print_zero(val, tab, tab->wdt - ft_counter_number(*val));
    else
    {
        if (tab->dash)
        {
            ft_putnbr_fd(*val, 1);
            tab->tl += ft_counter_number(*val);
        }
        print_space(val, tab, tab->wdt - ft_counter_number(*val));
    }
}

void    print_unsigned_int(const char *format, int i, t_args *tab)
{
    unsigned int     val;

    val = va_arg(tab->args, unsigned int);
    //tab->sign = 1;
    if (tab->pnt && !tab->wdt && !tab->is_zero)
        handling_precision(tab, &val);
    else if (!tab->pnt && tab->wdt)
        handling_width(tab, &val);
    else if (tab->pnt && tab->wdt)
        handling_width_and_precision(tab, &val);
    if (!tab->dash)
    {
        ft_putnbr_fd(val, 1);
        tab->tl += ft_counter_number(val);
    }
}
