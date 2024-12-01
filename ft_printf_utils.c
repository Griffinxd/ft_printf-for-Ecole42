/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanav <ymanav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:56:39 by ymanav            #+#    #+#             */
/*   Updated: 2024/12/01 18:58:18 by ymanav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)"));
	len = 0;
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}

int	ft_putnbr(int num)
{
	int	len;

	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	len = 0;
	if (num < 0)
	{
		len += ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		len += ft_putnbr(num / 10);
	len += ft_putchar("0123456789"[num % 10]);
	return (len);
}

int	ft_putunsnbr(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_putunsnbr(num / 10);
	len += ft_putchar("0123456789"[num % 10]);
	return (len);
}

int	ft_puthex(unsigned long num, char c)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthex(num / 16, c);
	if (c == 'x')
		len += ft_putchar("0123456789abcdef"[num % 16]);
	else if (c == 'X')
		len += ft_putchar("0123456789ABCDEF"[num % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	addr;

	addr = (unsigned long)ptr;
	len = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	if (addr == 0)
		len += ft_putchar('0');
	else
		len += ft_puthex(addr, 'x');
	return (len);
}
