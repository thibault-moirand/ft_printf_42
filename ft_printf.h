/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoirand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:47 by tmoirand          #+#    #+#             */
/*   Updated: 2023/10/19 16:29:49 by tmoirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_puthex(unsigned long n, const char form);
int		ft_putnbre(int n);
int		ft_putnbree(unsigned int n);
int		ft_putchar(char b);
int		ft_putstr(char *b);
char	*ft_strdup(const char *src);
int		ft_printf(const char *format, ...);

#endif
