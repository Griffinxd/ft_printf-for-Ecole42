/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanav <ymanav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:01:47 by ymanav            #+#    #+#             */
/*   Updated: 2024/12/01 18:22:30 by ymanav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int num);
int	ft_putunsnbr(unsigned int num);
int	ft_puthex(unsigned long num, char c);
int	ft_putptr(void *ptr);
int	ft_format(va_list args, char specifier);
int	ft_isflag(char c);
int	ft_printf(const char *str, ...);

#endif