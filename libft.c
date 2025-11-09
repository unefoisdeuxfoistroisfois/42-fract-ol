/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:46:54 by britela-          #+#    #+#             */
/*   Updated: 2025/11/09 12:52:24 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	ft_atoi_julia2(char *str, int i)
{
	double	res;
	double	fraction;

	res = 0.0;
	if (str[i] == '.')
		i++;
	fraction = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + (str[i] - '0') * fraction;
		fraction = fraction * 0.1;
		i++;
	}
	return (res);
}

double	ft_atoi_julia(char *str)
{
	int		i;
	int		sign;
	double	res;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	res = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + (str[i] - '0');
		i++;
	}
	res = res + ft_atoi_julia2(str, i);
	res = res * sign;
	return (res);
}
