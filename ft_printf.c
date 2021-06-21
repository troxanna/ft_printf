#include "ft_printf.h"

static t_args *ft_initialise_tab(t_args *tab)                       
{                       
      tab->wdt = 0;        // we set everything to 0, false        
      tab->prc = 0;                        
      tab->zero = 0;                        
      tab->pnt = 0;                        
      tab->sign = 0;                        
      tab->tl = 0;                        
      tab->is_zero = 0;                        
      tab->dash = 0;                        
      tab->perc = 0;                        
      tab->sp = 0;                        
      return (tab);                       
}

int       ft_printf(const char *format, ...)
{
    t_args *tab;
    int     i;
    int     len;

    tab = (t_args *)malloc(sizeof(t_args));
    if (!tab)
        return (-1);
    ft_initialise_tab(tab);
    va_start(tab->args, format);
    i = 0;
    len = 0;

    while (format[i])
    {
        if (format[i] == '%')
            i = ft_parser(tab, format, i + 1);
        else
            len+= write(1, &format[i++], 1);
    }
    len = len + tab->tl;
    //printf ("\n%d\n", len);
    va_end(tab->args);
    free(tab);
    return (len);
}

