/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:55:12 by britela-          #+#    #+#             */
/*   Updated: 2025/05/18 13:26:41 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	resultats1;
	int	resultats2;
	int	x = 42;

	resultats1 = ft_printf("%j\n");
	resultats2 = printf("%j\n");
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Charactere : %c\n", 'B');
	resultats2 = printf("Charactere : %c\n", 'B');
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("String : %s\n", "Salut comment tu vas ?");
	resultats2 = printf("String : %s\n", "Salut comment tu vas ?");
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Adresse : %p\n", NULL);
	resultats2 = printf("Adresse : %p\n", NULL);
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Decimal : %d\n", -4219);
	resultats2 = printf("Decimal : %d\n", -4219);
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Entier : %i\n", 151);
	resultats2 = printf("Entier : %i\n", 151);
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Unsigned int : %u\n", 6543);
	resultats2 = printf("Unsigned int : %u\n", 6543);
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Hexa minuscule : %x\n", 48879);
	resultats2 = printf("Hexa minuscule : %x\n", 48879);
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Hexa MAJUSCULE : %X\n", 48879);
	resultats2 = printf("Hexa MAJUSCULE : %X\n", 48879);
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	resultats1 = ft_printf("Pourcentage : %%\n");
	resultats2 = printf("Pourcentage : %%\n");
	printf("ft_printf: %d chars | printf: %d chars\n\n", resultats1, resultats2);

	return (0);
}
