/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:48:28 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/12 16:00:35 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int main()
{
	// int		d = 47;
	// char	*s = "ab";
	// char	c = 'A';
	int		p = 0;
	int		ft_p;

	// ft_p = ft_printf("%d|%-d|%23d|%.5d|%.50d|%-23d|%-.5d|%-.50d|%23.5d|%23.50d|%-23.5d|%-23.50d", 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256);
	// ft_p =  ft_printf("%10d", 256);
	// ft_putendl("");
	// p = printf("%d|%0d|% d|%-d|%23d|%.2d|%.5d|%.50d|%-23d|%-.5d|%-.50d|%23.5d|%23.50d|%-23.5d|%-23.50d|% -23.50d", 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256);
	// ft_p =  ft_printf("%+0d|%+- 02.5d|%-+d|%d|% d|%0d", 1, 2, 3, 4, 5, 6);
	// ft_p =  ft_printf("%+0d|%+- 02.5d|%-+d| meow lol", 1, 2, 3);
	// ft_p = ft_printf("%c|%-10.3s|%+- 025.3d|%+ 10d|", 'A', "Meow", 256,10);
	// ft_putendl("");
	ft_p =	ft_printf("%ld|%-ld|%+ld|% ld|%0ld", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	// ft_putendl("");
	p += 	 printf("\n%ld|%-ld|%+ld|% ld|%0ld", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	// ft_p =	ft_printf("%.50ld|%-ld|%+ld|% ld|%0ld", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);
	// // ft_putendl("");
	// p += 	 printf("\n%.50ld|%-ld|%+ld|% ld|%0ld", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);

	printf("\nftp : %d, p : %d", ft_p, p);
	// ft_putendl("");
	// p =  	printf("%d|%-d|%+d|% d|%0d", 256, 256, 256, 256, 256);
	// ft_putnbr(LLONG_MAX);
	// ft_putendl("");
	// ft_putnbr(p);
	// ft_putendl("");
	return (0);
}
