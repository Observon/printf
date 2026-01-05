/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:58:12 by eride-ol          #+#    #+#             */
/*   Updated: 2025/11/28 13:58:12 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_specifier(char spec, va_list *ap);
static int	ft_print_invalid(char spec);
static int	ft_process_format(const char *format, va_list *ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = ft_process_format(format, &ap);
	va_end(ap);
	return (count);
}

static int	ft_process_format(const char *format, va_list *ap)
{
	int	count;
	int	tmp;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			tmp = ft_handle_specifier(*(++format), ap);
		else
			tmp = ft_putchar_count(*format);
		if (tmp < 0)
			return (-1);
		count += tmp;
		if (*format)
			format++;
	}
	return (count);
}

static int	ft_handle_specifier(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	if (spec == 's')
		return (ft_print_string(va_arg(*ap, const char *)));
	if (spec == 'p')
		return (ft_print_pointer(va_arg(*ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_number(va_arg(*ap, int)));
	if (spec == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	if (spec == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), 0));
	if (spec == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), 1));
	if (spec == '%')
		return (ft_putchar_count('%'));
	return (ft_print_invalid(spec));
}

static int	ft_print_invalid(char spec)
{
	return (ft_putchar_count(spec));
}
