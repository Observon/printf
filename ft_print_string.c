#include "ft_printf.h"

int	ft_print_string(const char *s)
{
	if (!s)
		return (ft_putstr_count("(null)"));
	return (ft_putstr_count(s));
}
