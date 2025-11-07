/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:09:11 by britela-          #+#    #+#             */
/*   Updated: 2025/05/16 18:42:21 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_16(unsigned long n, char letter)
{
	char	*baselow;
	char	*baseupper;
	int		cpt;

	baselow = "0123456789abcdef";
	baseupper = "0123456789ABCDEF";
	cpt = 0;
	if (n >= 16)
	{
		cpt = cpt + ft_putnbr_16(n / 16, letter);
	}
	if (letter == 'p' || letter == 'x')
	{
		cpt = cpt + ft_putchar(baselow[n % 16]);
	}
	else if (letter == 'X')
	{
		cpt = cpt + ft_putchar(baseupper[n % 16]);
	}
	return (cpt);
}
