/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanav <ymanav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:01:40 by ymanav            #+#    #+#             */
/*   Updated: 2024/12/01 18:58:24 by ymanav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_isflag(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_format(va_list args, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (specifier == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		len += ft_putunsnbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 'x');
	else if (specifier == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 'X');
	else if (specifier == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (specifier == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		charsprinted;
	va_list	args;

	va_start(args, str);
	charsprinted = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_isflag(*str) && *str)
				charsprinted += ft_format(args, *str);
		}
		else
			charsprinted += ft_putchar(*str);
		++str;
	}
	va_end(args);
	return (charsprinted);
}
