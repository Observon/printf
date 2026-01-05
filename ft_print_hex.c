/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:58:47 by eride-ol          #+#    #+#             */
/*   Updated: 2025/11/28 13:58:47 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	if (uppercase)
		return (ft_putnbr_base((unsigned long)n, "0123456789ABCDEF"));
	return (ft_putnbr_base((unsigned long)n, "0123456789abcdef"));
}
