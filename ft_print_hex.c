#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	if (uppercase)
		return (ft_putnbr_base((unsigned long)n, "0123456789ABCDEF"));
	return (ft_putnbr_base((unsigned long)n, "0123456789abcdef"));
}
