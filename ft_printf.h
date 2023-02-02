/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:46:29 by mkramer           #+#    #+#             */
/*   Updated: 2023/01/24 18:24:32 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	print_number(int nb);
int	print_character(char c);
int	ft_check_format(char c, va_list *ptr);
int	ft_printf(const char *format, ...);
int	print_address(unsigned long int nb);
int	print_unsigned_number(unsigned int nb);
int	print_hex(unsigned int nb, int s);
int	print_string(char	*str);
#endif