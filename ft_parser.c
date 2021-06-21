#include "ft_printf.h"

static int     parse_flag(const char *format, int i, t_args *tab)
{
	while (format[i] == '-' || format[i] == '0')
		if (format[i] == '-')
		{
			tab->dash = 1;
			i++;
		}
		else if (format[i] == '0' && tab->dash != 1)
		{
			tab->zero= 1;
			i++;
		}
		else if (format[i] == '0')
			i++;
	return (i);
}

static int     parse_width(const char *format, int i, t_args *tab)
{
    if (format[i] == '*')
    {
        tab->wdt = (va_arg(tab->args, int));
        i++;
    }
    else if (ft_isdigit(format[i])
        || (format[i] == '-' && ft_isdigit(format[i + 1])))
    {
        tab->wdt = ft_atoi(format + i);
        i = i + ft_counter_number(tab->wdt);
    }
    else if (format[i] == '0')
    {
        if (format[i] == '0')
            i++;
    }
    return(i);
}

static int     parse_prec(const char *format, int i, t_args *tab)
{
    i++;
    if (format[i] == '*')
    {
        tab->prc = (va_arg(tab->args, int));
        tab->pnt = 1;
        i++;
    }
    else if (ft_isdigit(format[i])
        || (format[i] == '-' && ft_isdigit(format[i + 1])))
    {
        tab->pnt = 1;
        tab->prc = ft_atoi(format + i);
        i = i + ft_counter_number(tab->prc);
    }
    else if (format[i] == '0' || (!ft_isdigit(format[i])
        && ft_strrchr("diupXxcs", format[i])))
    {
        tab->is_zero = 1;
        if (format[i] == '0')
            i++;
    }
    if (tab->prc < 0)
            tab->prc = 0;
    return(i);
}


int     parse_type(const char *format, int i, t_args *tab)
{
    if (format[i] == 'd' || format[i] == 'i')
        print_int(format, i, tab);
    else if (format[i] == 'u')
        print_unsigned_int(format, i, tab);
    else if (format[i] == 'c')
        print_char(format, i, tab);
    else if (format[i] == 's')
        print_string(format, i, tab);
    else if (format[i] == 'x' || format[i] == 'X')
        print_hex(format, i, tab);
    else if (format[i] == 'p')
        print_pointer(format, i, tab);
    return (i + 1);
}

int     ft_parser(t_args *tab, const char *format, int i)
{
    if (format[i] == '-' || format[i] == '0')
        i = parse_flag(format, i, tab);
    if (ft_isdigit(format[i]) || format[i] == '*')
        i = parse_width(format, i, tab);
    if (format[i] == '.')
        i = parse_prec(format, i, tab);
    if (ft_strrchr("diupXxcs", format[i]))
        i = parse_type(format, i, tab);
    return (i);
}

