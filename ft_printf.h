#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"


typedef struct s_args
{
    va_list  args;   //arg to print out                    
      int   wdt;     // width                
      int   prc;        // precision              
      int   zero;       // zero padding               
      int   pnt;        // .     
      int   dash;       // -               
      int   tl;         // total_length (return value)              
    int   sign;       // pos or neg number               
    int   is_zero;    // is number zero                 
    int   perc;       // %               
    int   sp;         // space flag ' '    
}               t_args;

int     ft_counter_number(int nb);
int			ft_counter_hex(long unsigned int n);
void	  ft_puthex_fd(long unsigned int n, int type, int fd);
void    print_pointer(const char *format, int i, t_args *tab);
void    print_hex(const char *format, int i, t_args *tab);
void    print_int(const char *format, int i, t_args *tab);
void    print_unsigned_int(const char *format, int i, t_args *tab);
void    print_char(const char *format, int i, t_args *tab);
void    print_string(const char *format, int i, t_args *tab);
int     ft_parser(t_args *tab, const char *format, int i);

#endif