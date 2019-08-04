/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:16:09 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/29 16:16:11 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

union	u_d
{
	double	d;
	t_d		ud;
};

union	u_ld
{
	long double	ld;
	t_ld		uld;
};


void			f_proc(const char *frm, va_list ap, int *i, int *sz)
{
	long double	ld;
	double		d;
	char		**s;
	t_flags		flgs;
	union u_d	ud;
	union u_ld	uld;

	get_flgs(frm, &flgs, i, 'f');
	if (flgs.L)
	{
		ld = va_arg(ap, long double);
		uld.ld = ld;
	}
	else if (flgs.l)
	{
		d = va_arg(ap, double);
		ud.d = d;
	}
	// printf("\nmi : %d, plus : %d, space : %d, zero : %d, wd : %d, pr : %d, dot : %d, h : %d, l : %d,  L : %d \n",
	// flgs.mi, flgs.plus, flgs.space, flgs.zero, flgs.wd, flgs.pr, flgs.dot, flgs.h, flgs.l, flgs.lcap);
	*sz += 0;
}