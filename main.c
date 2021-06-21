#include "ft_printf.h"

int     main(void)
{
    printf("%14c  l\n", 'h');
    ft_printf("%.14X  l", 13);
    printf("\n\n\n");
}