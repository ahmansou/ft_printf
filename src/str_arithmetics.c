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

char			*str_add(char *a, char *b)
{
	char	*res;
	char	rst[2];
	int		add[2];
	int		i;
	
	a = str_delzero(a);
	b = str_delzero(b);
	a = (ft_strlen(b) > ft_strlen(a)) ? str_addzero(b, a) : a;
	b = (ft_strlen(a) > ft_strlen(b)) ? str_addzero(a, b) : b;
	ft_printf("%s + %s\n", a, b);
	i = ft_strlen(a);
	res = ft_strnew(i + 1);
	ft_memset(&rst, '0', 2);
	while (i >= 0)
	{
		if (i > 0 && (add[0] = a[i - 1] - '0') + 1)
		{
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

static	char	*do_mul(char *a, char *b, char *tmp, char *prd)
{
	int		i[3];
	char	rst[2];
	char	pr[3];

	i[1] = ft_strlen(b);
	while (--i[1] >= 0)
	{
		i[2] = ft_strlen(a);
		i[0] = (ft_strlen(a) + ft_strlen(b) - 1) - (ft_strlen(b) - (i[1] + 1));
		ft_memset(&rst, '0', 2);
		ft_memset(tmp, '0', ft_strlen(a) + ft_strlen(b));
		while (--i[2] >= 0)
		{
			pr[0] = b[i[1]] - '0';
			pr[1] = a[i[2]] - '0';
			rst[1] = ((pr[0] * pr[1] + rst[0] - '0') % 10) + '0';
			rst[0] = (((pr[0] * pr[1]  + rst[0] - '0') / 10) % 10) + '0';
			tmp[i[0]--] = rst[1];
		}
		tmp[i[0]] = rst[0];
		prd = str_add(prd, tmp);
	}
	return (prd);
}

char			*str_mul(char *a, char *b)
{
	char	*prd;
	char	*tmp;

	a = str_delzero(a);
	b = str_delzero(b);
	prd = ft_strnew(ft_strlen(a) + ft_strlen(b));
	ft_memset(prd, '0', ft_strlen(a) + ft_strlen(b));
	tmp = ft_strnew(ft_strlen(a) + ft_strlen(b));
	prd = do_mul(a, b, tmp, prd);
	// prd = str_delzero(prd);
	return (prd);
}

char		*str_pow(char *a, int pow)
{
	char	*prd;

	prd = ft_strdup("1");
	// prd = ft_strnew(1);
	// ft_memset(prd, '1', 1);
	while (pow > 0)
	{
		prd = str_mul(prd, a);
		pow--;
	}
	return prd;
}