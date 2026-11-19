/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:56:45 by tmoirand          #+#    #+#             */
/*   Updated: 2023/10/19 11:56:47 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_trie(const char format, va_list args)
{
	unsigned long	p;
	int				nb;

	nb = 0;
	if (format == 'c')
		nb += ft_putchar(va_arg(args, int));
	else if (format == 's')
		nb += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		p = va_arg(args, unsigned long);
		if (p == 0)
			nb += ft_putstr("(nil)");
		else
		{
			nb += ft_putstr("0x");
			nb += ft_puthex(p, format);
		}
	}
	return (nb);
}

int	ft_triee(const char format, va_list args)
{
	int	nb;

	nb = 0;
	if (format == 'd' || format == 'i')
		nb += ft_putnbre(va_arg(args, int));
	else if (format == 'u')
		nb += ft_putnbree(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		nb += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		nb += ft_putchar('%');
	return (nb);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		nb;
	va_list	args;

	va_start(args, format);
	i = -1;
	nb = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			nb += ft_trie(format[i], args);
			nb += ft_triee(format[i], args);
		}
		else
			nb += ft_putchar(format[i]);
	}
	va_end(args);
	return (nb);
}
