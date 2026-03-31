#include "ft_printf.h"

int	ft_print_number(int n)
{
	unsigned int	nbr;
	int				count;
	int				tmp;

	count = 0;
	if (n < 0)
	{
		tmp = ft_putchar_count('-');
		if (tmp < 0)
			return (-1);
		count += tmp;
		nbr = (unsigned int)(-(long)n);
	}
	else
		nbr = (unsigned int)n;
	tmp = ft_putnbr_base((unsigned long)nbr, "0123456789");
	if (tmp < 0)
		return (-1);
	return (count + tmp);
}
