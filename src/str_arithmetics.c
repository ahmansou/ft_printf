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
	char	*r;
	char	*c;
	int		i;

	a = str_delzero(a);
	b = str_delzero(b);
	a = (ft_strlen(b) > ft_strlen(a)) ? str_addzero(b, a) : a;
	b = (ft_strlen(a) > ft_strlen(b)) ? str_addzero(a, b) : b;
	i = ft_strlen(a);
	r = ft_strnew(i + 1);
	c = ft_strnew(2);
	c[0] = '0';
	c[1] = '0';
	while (i >= 1)
	{
		c[1] = (a[i - 1] + b[i - 1] + c[0] - 144) % 10 + 48;
		c[0] = (a[i - 1] + b[i - 1] + c[0] - 144) / 10 + 48;
		r[i--] = c[1];
	}
	r[i] = ((c[0] - 48) % 10) + 48;
	return (r);
}

static	char	*do_mul(char *a, char *b, char *tmp, char *prd)
{
	int		i[3];
	char	*c;
	char	*t;

	i[1] = ft_strlen(b);
	c = ft_strnew(2);
	while (--i[1] >= 0)
	{
		i[2] = ft_strlen(a);
		i[0] = (ft_strlen(a) + ft_strlen(b) - 1) - (ft_strlen(b) - (i[1] + 1));
		ft_memset(c, '0', 2);
		ft_memset(tmp, '0', ft_strlen(a) + ft_strlen(b));
		while (--i[2] >= 0)
		{
			c[1] = ((a[i[2]] - 48) * (b[i[1]] - 48) + c[0] - 48) % 10 + 48;
			c[0] = ((a[i[2]] - 48) * (b[i[1]] - 48) + c[0] - 48) / 10 + 48;
			tmp[i[0]--] = c[1];
		}
		tmp[i[0]] = c[0];
		t = prd;
		prd = str_add(t, tmp);
		free(t);
	}
	free(c);
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
	free(tmp);
	return (prd);
}

char		*str_pow(char *a, int pow)
{
	char	*prd;
	char	*tmp;

	prd = ft_strnew(1);
	ft_memset(prd, '1', 1);
	while (pow > 0)
	{
		tmp = prd;
		prd = str_mul(tmp, a);
		free(tmp);
		pow--;
	}
	return prd;
}