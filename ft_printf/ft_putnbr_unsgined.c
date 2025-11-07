/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsgined.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:01:09 by britela-          #+#    #+#             */
/*   Updated: 2025/05/16 18:42:41 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	cpt;

	cpt = 0;
	if (nb < 10)
	{
		cpt = cpt + ft_putchar(nb + '0');
	}
	else
	{
		cpt = cpt + ft_putnbr_unsigned(nb / 10);
		cpt = cpt + ft_putnbr_unsigned(nb % 10);
	}
	return (cpt);
}
