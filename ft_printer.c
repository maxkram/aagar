/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:46:04 by mkramer           #+#    #+#             */
/*   Updated: 2023/01/25 16:20:24 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_number(n / 10);
		len += print_number(n % 10);
	}
	if (n < 10)
		len += print_character(n + 48);
	return (len);
}

int	print_address(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_address(nb / 16);
		len += print_address(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_character(nb + 48);
		else
			len += print_character(nb + 87);
	}
	return (len);
}

int	print_unsigned_number(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += print_unsigned_number(nb / 10);
		len += print_unsigned_number(nb % 10);
	}
	if (nb < 10)
		len += print_character(nb + 48);
	return (len);
}

int	print_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, s);
		len += print_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_character(nb + 48);
		else
		{
			if (s == 1)
				len += print_character(nb + 87);
			else
				len += print_character(nb + 55);
		}
	}
	return (len);
}

int	print_string(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
