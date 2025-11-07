/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:48:09 by britela-          #+#    #+#             */
/*   Updated: 2025/05/18 14:30:37 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_char(const char *format, va_list args, int i)
{
	int	cpt;

	cpt = 0;
	if (format[i + 1] == 'c')
		cpt = cpt + ft_putchar(va_arg(args, int));
	else if (format[i + 1] == 's')
		cpt = cpt + ft_putstr(va_arg(args, char *));
	else if (format[i + 1] == 'p')
		cpt = cpt + ft_pointer(va_arg(args, void *));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		cpt = cpt + ft_putnbr(va_arg(args, int));
	else if (format[i + 1] == 'u')
		cpt = cpt + ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		cpt = cpt + ft_putnbr_16(va_arg(args, unsigned int), format[i + 1]);
	else if (format[i + 1] == '%')
		cpt = cpt + ft_putchar('%');
	return (cpt);
}

int	ft_exists(const char *format, int i)
{
	if (format[i] == '%' && format[i + 1] != '\0'
		&& (format[i + 1] == 'c' || format[i + 1] == 's'
			|| format[i + 1] == 'p' || format[i + 1] == 'd'
			|| format[i + 1] == 'i' || format[i + 1] == 'u'
			|| format[i + 1] == 'x' || format[i + 1] == 'X'
			|| format[i + 1] == '%'))
	{
		return (1);
	}
	return (0);
}

int	ft_percentage(const char *format, va_list args, int i)
{
	int	cpt;

	cpt = 0;
	if (ft_exists(format, i) == 1)
	{
		cpt = cpt + ft_check_char(format, args, i);
		return (cpt);
	}
	else
	{
		cpt = cpt + ft_putchar('%');
		return (cpt);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			cpt = cpt + ft_percentage(format, args, i);
			i = i + 2;
		}
		else
		{
			cpt = cpt + ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (cpt);
}
