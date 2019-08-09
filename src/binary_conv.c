/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:04:59 by ahmansou          #+#    #+#             */
/*   Updated: 2019/08/04 17:05:01 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mant_addzero(char *mant, int sz)
{
	char	*a;
	int		i;
	int		j;

	a = ft_strnew(sz);
	ft_memset(a, '0', sz);
	i = ft_strlen(a) - 1;
	j = ft_strlen(mant) - 1;
	while (j >= 0)
		a[i--] = mant[j--];
	return (a);
}
