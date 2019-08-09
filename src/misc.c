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

int		print_fd(char *pow, int lenp, int pnt, int pr)
{
	int indx;
	int count;

	indx = 0;
	count = 0;
	while (indx < lenp - pnt)
		ft_putchar(pow[indx++]);
	count += write(1, ".", 1);
	while (indx < pr + lenp - pnt && pow[indx])
		ft_putchar(pow[indx++]);
	count += indx;
	if (pr >= pnt)
		count += put_zero(pr - pnt);
	return (count);
}

int		print_f(char *pow, int lenp, int pnt, int pr)
{
	int indx;
	int count;

	indx = 0;
	count = 0;
	while (indx < lenp - pnt)
		ft_putchar(pow[indx++]);
	while (indx < pr + lenp - pnt && pow[indx])
		ft_putchar(pow[indx++]);
	count += indx;
	if (pr >= pnt)
		count += put_zero(pr - pnt);
	return (count);
}

int p_fsubd(char *s, int len, int pnt, int pr)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (i + 1< len - pnt && (s[i + 1]))
		i++;
	c += write(1, &s[i++], 1);
	c += write(1, ".", 1);
	j = 0;
	while (j <= pr && s[i + j])
		c += write(1, &s[i + j++], 1);
	c += put_zero(pr - j);
	return (c);
}

int p_fsub(char *s, int len, int pnt)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i + 1< len - pnt && (s[i + 1]))
		i++;
	c += write(1, &s[i++], 1);
	return (c);
}