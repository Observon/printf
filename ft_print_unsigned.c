#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_base((unsigned long)n, "0123456789"));
}
