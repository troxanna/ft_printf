#include "ft_printf.h"

static void    print_space(long unsigned int *val, t_args *tab, int max)
{
    int i;

    i = 0;
    while (i++ < max)
        ft_putchar_fd(' ', 1);
    tab->tl += i;
}

static void    print_zero(long unsigned int *val, t_args *tab, int max)
{
    int i;

    i = 0;
    while (i++ < max)
        ft_putchar_fd('0', 1);
    tab->tl += i;
}

static void    handling_width_and_precision(t_args *tab, long unsigned int *val, int type)
{
    int i;

    i = 0;
    if (tab->wdt > tab->prc)
    {
        if (tab->dash)
        {
            if (*val < 0)
            {
                *val = *val * (-1);
                i = 1;
                ft_putchar_fd('-', 1);
            }
            print_zero(val, tab, tab->prc - ft_counter_hex(*val));
            ft_puthex_fd(*val, type, 1);
            print_space(val, tab, tab->wdt - tab->prc - i);
        }
        else
        {
            if (*val < 0)
            {
                *val = *val * (-1);
                i = 1;
            }
            print_space(val, tab, tab->wdt - tab->prc - i);
            if (i == 1)
                ft_putchar_fd('-', 1);
            print_zero(val, tab, tab->prc - ft_counter_hex(*val));
        }
    }
    else
        print_zero(val, tab, tab->prc - ft_counter_hex(*val));
}


static void    handling_precision(t_args *tab, long unsigned int *val, int type)
{
    if (*val < 0)
    {
        *val = *val * (-1);
        ft_putchar_fd('-', 1);
    }
    print_zero(val, tab, tab->prc - ft_counter_hex(*val));
}

static void    handling_width(t_args *tab, long unsigned int *val, int type)
{
    int i;

    i = 0;
    if (tab->zero)
        print_zero(val, tab, tab->wdt - ft_counter_hex(*val));
    else
    {
        if (tab->dash)
        {
            ft_puthex_fd(*val, type,1);
            tab->tl += ft_counter_hex(*val);
        }
        if (*val < 0)
            i = 2;
        print_space(val, tab, tab->wdt - ft_counter_hex(*val) - i);
    }
}

void    print_hex(const char *format, int i, t_args *tab)
{
    long unsigned int     val;
    int type;

    type = 'X';
    if (format[i] == 'x')
        type = 'x';
    val = va_arg(tab->args, long unsigned int);
    //tab->sign = 1;
    if (tab->pnt && !tab->wdt && !tab->is_zero)
        handling_precision(tab, &val, type);
    else if (!tab->pnt && tab->wdt)
        handling_width(tab, &val, type);
    else if (tab->pnt && tab->wdt)
        handling_width_and_precision(tab, &val, type);
    if (!tab->dash)
    {
        ft_puthex_fd(val, type, 1);
        tab->tl += ft_counter_hex(val);
    }
}
