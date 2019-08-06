/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:13:03 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/13 19:00:09 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const	t_types	v_types =
{
	{ "csdoiuxpf"},
	{ &c_proc, &s_proc, &d_proc, &o_proc,
		&d_proc, &u_proc, &x_proc, &p_proc, &f_proc}
};

t_types	get_types()
{
	return (v_types);
}

int		put_space(int sp_sz)
{
	int c;

	c = 0;
	while (sp_sz > 0)
	{
		c += write(1, " ", 1);
		sp_sz--;
	}
	return (c);
}

int		put_zero(int z_sz)
{
	int c;

	c = 0;
	while (z_sz > 0)
	{
		c += write(1, "0", 1);
		z_sz--;
	}
	return (c);
}

int		n_len(long long n)
{
	long long tmp;
	int size;

	tmp = n;
	size = 1;
	while ((tmp = tmp / 10))
		size++;
	return (size);
}

int		print_f(char *pow, int lenp, int pnt, int pr)
{
	int indx;
	int count;

	indx = 0;
	count = 0;
	while (indx < lenp - pnt)
		ft_putchar(pow[indx++]);
	ft_putchar('.');
	count += indx + 1;
	while (pow[indx])
		ft_putchar(pow[indx++]);
	count += indx;
	if (pr >= pnt)
		count += put_zero(pr - pnt);
	return (count);
}