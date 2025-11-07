/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:14:51 by britela-          #+#    #+#             */
/*   Updated: 2025/05/16 18:42:00 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char	*str)
{
	int	i;
	int	cpt;

	if (str == NULL)
	{
		return (ft_putstr("(null)"));
	}
	i = 0;
	cpt = 0;
	while (str[i] != '\0')
	{
		cpt = cpt + ft_putchar(str[i]);
		i++;
	}
	return (cpt);
}
