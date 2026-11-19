/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:56:35 by tmoirand          #+#    #+#             */
/*   Updated: 2023/10/19 11:56:38 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbre(int n)
{
	char	c[10];
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		nb += ft_putchar(45);
		n = -n;
	}
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		c[i] = (n % 10);
		n /= 10;
		i++;
	}
	while (i-- > 0)
		nb += ft_putchar(c[i] + '0');
	return (nb);
}

int	ft_puthex(unsigned long n, const char form)
{
	char	c[17];
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		if (form == 'X')
			c[i++] = "0123456789ABCDEF"[n % 16];
		else
			c[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (i-- > 0)
		nb += ft_putchar(c[i]);
	return (nb);
}

int	ft_putnbree(unsigned int n)
{
	char	c[10];
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		c[i] = (n % 10);
		n /= 10;
		i++;
	}
	while (i-- > 0)
		nb += ft_putchar(c[i] + '0');
	return (nb);
}

int	ft_putchar(char b)
{
	write (1, &b, 1);
	return (1);
}

int	ft_putstr(char *b)
{
	int	i;

	if (b == NULL)
		return (ft_putstr("(null)"));
	i = 0;
	while (b[i])
	{
		ft_putchar(b[i]);
		i++;
	}
	return (i);
}
