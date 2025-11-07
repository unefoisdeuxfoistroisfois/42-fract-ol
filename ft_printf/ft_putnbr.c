/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:39:59 by britela-          #+#    #+#             */
/*   Updated: 2025/05/16 17:59:55 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	cpt;

	cpt = 0;
	if (nb == -2147483648)
	{
		cpt = cpt + ft_putchar('-');
		cpt = cpt + ft_putchar('2');
		cpt = cpt + ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		cpt = cpt + ft_putchar('-');
		nb = -nb;
		cpt = cpt + ft_putnbr(nb);
	}
	else if (nb >= 0 && nb < 10)
		cpt = cpt + ft_putchar(nb + 48);
	else if (nb >= 10)
	{
		cpt = cpt + ft_putnbr(nb / 10);
		cpt = cpt + ft_putnbr(nb % 10);
	}
	else
		cpt = cpt + ft_putchar(nb + 48);
	return (cpt);
}
