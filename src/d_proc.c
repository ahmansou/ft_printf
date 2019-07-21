/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:36:16 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/16 10:36:19 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	long	get_va_arg(va_list ap, t_flags flgs)
{
	if (flgs.h == 1)
		return ((short)va_arg(ap, int));
	else if (flgs.h == 2)
		return ((char)va_arg(ap, int));
	else if (flgs.l == 1)
		return (va_arg(ap, long));
	else if (flgs.l == 2)
		return (va_arg(ap, long long));
	else
		return (va_arg(ap, int));
}
/**
***no minus
**/

static	int		sub_w(t_flags flgs, long long d)
{
	int c;
	
	c = 0;
	c += (flgs.plus || flgs.space) ? 1 : 0;
	c += (flgs.prec > n_len(d)) ? flgs.prec : n_len(d);
	return (c);
}

static	void	no_m_d(long long d, t_flags *flgs, int *sz)
{
	flgs->width -= sub_w(*flgs, d);
	ft_putnbr(flgs->width);
	*sz += (!flgs->zero && flgs->width > n_len(d)) ?
		put_space(flgs->width) : 0;
	if (flgs->plus)
		*sz += write(1, "+", 1);
	else if (flgs->space)
		*sz += write(1, " ", 1);
	*sz += (flgs->zero && !flgs->dot && flgs->width > n_len(d)) ?
		put_zero(flgs->width) : 0;
	if (flgs->prec > n_len(d))
		*sz += put_zero(flgs->prec - n_len(d));
	ft_putnbr(d);
}
/**
***yes minus
**/
static	void	m_d(long long d, t_flags *flgs, int *sz)
{
	if (flgs->plus)
	{
		*sz += write(1, "+", 1);
		flgs->width--;
	}
	else if (flgs->space)
	{
		*sz += write(1, " ", 1);
		flgs->width--;
	}
	if (flgs->prec > n_len(d))
	{
		*sz += put_zero(flgs->prec - n_len(d));
		flgs->width -= flgs->prec - n_len(d);
	}
	ft_putnbr(d);
	flgs->width -= n_len(d);
	*sz += put_space(flgs->width) + n_len(d);
}


/**
*** flags : 0 = '-', 1 = '+', 2 = ' ', 3 = '0', 4 = width, 5 = prec
**/
void			d_proc(const char *frm, va_list ap, int *i, int *sz)
{
	long long	d;
	char		*t;
	t_flags 	flgs;

	get_flgs(frm, &flgs, i);
	d = get_va_arg(ap, flgs);
	if (flgs.minus)
		m_d(d, &flgs, sz);
	else
		no_m_d(d, &flgs, sz);
	
	// *sz += n_len(d);
}