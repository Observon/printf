#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long	n;
	int				count;
	int				tmp;

	if (!ptr)
		return (ft_putstr_count("(nil)"));
	n = (unsigned long)ptr;
	count = ft_putstr_count("0x");
	if (count < 0)
		return (-1);
	tmp = ft_putnbr_base(n, "0123456789abcdef");
	if (tmp < 0)
		return (-1);
	return (count + tmp);
}
