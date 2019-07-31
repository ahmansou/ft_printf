/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arithmetics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:07:17 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/30 15:07:22 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*str_addzero(char *s1, char *s2)
{
	char	*tmp;

	tmp = s2;
	s2 = ft_strnew(ft_strlen(s1) - ft_strlen(tmp));
	ft_memset(s2, '0', ft_strlen(s1) - ft_strlen(tmp));
	s2 = ft_strcat(s2, tmp);
	free(tmp);
	return (s2);
}

char			*str_add(char *a, char *b)
{
	char	*res;
	char	rst[2];
	int		add[2];
	int		i;

	b = (ft_strlen(a) > ft_strlen(b)) ? str_addzero(a, b) : b;
	a = (ft_strlen(b) > ft_strlen(a)) ? str_addzero(b, a) : a;
	i = ft_strlen(a);
	res = ft_strnew(i + 1);
	ft_memset(&rst, '0', 2);
	while (i >= 0)
	{
		if (i > 0)
		{
			add[0] = a[i - 1] - '0';
			add[1] = b[i - 1] - '0';
			rst[1] = ((add[0] + add[1] + (rst[0] - '0')) % 10) + '0';
			rst[0] = (((add[0] + add[1] + (rst[0] - '0')) / 10) % 10) + '0';
		}
		else
			rst[1] = ((rst[0] - '0') % 10) + '0';
		res[i--] = rst[1];
	}
	return (res);
}

// char			*str_div(char *a, char *b)
// {
// 	char	*res;
// 	char	*tmp;
// 	char	rst[2];
// 	int		i;
// 	int		j;

// 	i = 0;
// 	b = (ft_strlen(a) > ft_strlen(b)) ? str_addzero(a, b) : b;
// 	a = (ft_strlen(b) > ft_strlen(a)) ? str_addzero(b, a) : a;
// 	res = ft_strnew(ft_strlen(a) * ft_strlen(b));
// 	while (a[i])
// 	{
// 		j = 0;
// 		while (b[j])
// 		{
// 			rst[0] = ()
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (res);
// }