/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:09:14 by britela-          #+#    #+#             */
/*   Updated: 2025/05/19 19:32:54 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *ptr)
{
	unsigned long	ptr2;
	int				cpt;

	ptr2 = (unsigned long)ptr;
	cpt = 0;
	if (ptr == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	cpt = cpt + write(1, "0x", 2);
	cpt = cpt + ft_putnbr_16(ptr2, 'p');
	return (cpt);
}
