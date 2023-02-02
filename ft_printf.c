/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:46:16 by mkramer           #+#    #+#             */
/*   Updated: 2023/01/25 15:28:28 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_check_format(char c, va_list *ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_character(va_arg(*ptr, int));
	if (c == '%')
		len += write(1, "%", 1);
	if (c == 'd' || c == 'i')
		len += print_number(va_arg(*ptr, int));
	if (c == 'u')
		len += print_unsigned_number(va_arg(*ptr, unsigned int));
	if (c == 'x')
		len += print_hex(va_arg(*ptr, unsigned int), 1);
	if (c == 'X')
		len += print_hex(va_arg(*ptr, unsigned int), 2);
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += print_address(va_arg(*ptr, unsigned long int));
	}
	if (c == 's')
		len += print_string(va_arg(*ptr, char *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else
		{
			len += ft_check_format(format[i + 1], &ptr);
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
