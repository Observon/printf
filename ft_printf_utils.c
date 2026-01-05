/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:58:53 by eride-ol          #+#    #+#             */
/*   Updated: 2025/12/09 16:08:58 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_rec(unsigned long n, const char *base, size_t base_len);

int	ft_putchar_count(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr_count(const char *s)
{
	size_t	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (write(1, s, len) != (ssize_t)len)
		return (-1);
	return ((int)len);
}

int	ft_putnbr_base(unsigned long n, const char *base)
{
	size_t	base_len;

	if (!base)
		return (-1);
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (-1);
	return (ft_putnbr_rec(n, base, base_len));
}

static int	ft_putnbr_rec(unsigned long n, const char *base, size_t base_len)
{
	int	count;
	int	tmp;

	count = 0;
	if (n >= base_len)
	{
		tmp = ft_putnbr_rec(n / base_len, base, base_len);
		if (tmp < 0)
			return (-1);
		count += tmp;
	}
	tmp = ft_putchar_count(base[n % base_len]);
	if (tmp < 0)
		return (-1);
	return (count + tmp);
}
