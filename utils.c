#include "ft_printf.h"

int     ft_counter_number(int nb)
{
    int counter;

    counter = 1;
	if (nb > 9)
	{
		ft_counter_number(nb / 10);
		counter++;
	}
    return (counter);
}

int					ft_counter_hex(long unsigned int n)
{
	int		counter;

	counter = 1;
	while ((n = n / 16) > 0)
		counter++;
	return (counter);
}


void	ft_puthex_fd(long unsigned int n, int type, int fd)
{
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, type, 1);
		if (n % 16 < 10)
			ft_putchar_fd((n % 16 + 48), 1);
		else if (type == 'x')
			ft_putchar_fd((n % 16 + 87), 1);
		else
			ft_putchar_fd((n % 16 + 55), 1);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n % 16 + 48), 1);
		else if (type == 'x')
			ft_putchar_fd((n % 16 + 87), 1);
		else
			ft_putchar_fd((n % 16 + 55), 1);
	}
}
