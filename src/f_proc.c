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

static long double	get_va_arg_f(va_list ap, t_flags flgs)
{
	if (flgs.lcap == 1)
		return (va_arg(ap, long double));
	else
		return ((long double)va_arg(ap, double));
}

static char			*conv_mant(char *mant, int exp)
{
	int		i;
	char	*a;
	char	*tmpa;
	char	*pw;

	i = 0;
	a = ft_strnew(1);
	(exp = 0) ? ft_memset(a, '0', 1) : ft_memset(a, '1', 1);
	while (mant[i])
	{
		a = str_mul(a, "10", 1);
		if (mant[i] == '1')
		{
			pw = str_pow("5", i + 1);
			tmpa = a;
			a = str_add(a, pw);
			free(tmpa);
			free(pw);
		}
		i++;
	}
	return (a);
}

static void			rf_proc(t_flags *f, int *sz, char *mant, union u_ld ld)
{
	int			lp[2];
	char		*pow;

	mant = conv_mant(mant, ld.uld.exp);
	if (ld.uld.exp - 16383 < 0 && (lp[0] = ((ld.uld.exp - 16383) * -1) + 63))
		pow = str_pow("5", (ld.uld.exp - 16383) * -1);
	else
	{
		pow = str_pow("2", ld.uld.exp - 16383);
		lp[0] = 63;
	}
	pow = str_mul(pow, mant, 0);
	if (!(ld.ld > 0 && ld.ld < 1))
		pow = str_delzero(pow);
	lp[1] = (int)ft_strlen(pow);
	if (ld.ld > 0 && ld.ld < 1)
		sub_proc(f, sz, pow, lp);
	else
		rrf_proc(f, sz, pow, lp);
}

void				f_proc(const char *frm, va_list ap, int *i, int *sz)
{
	long double	ld;
	char		*mant;
	t_flags		flgs;
	union u_ld	uld;

	get_flgs(frm, &flgs, i, 'f');
	ld = get_va_arg_f(ap, flgs);
	uld.ld = ld;
	if ((flgs.pr < 0 || flgs.wd < 0) && (flgs.pr = 6))
		flgs.wd = 0;
	if (uld.uld.sign)
		flgs.plus = '-';
	if (ld == 0)
		z_proc(&flgs, sz);
	else
	{
		mant = mant_addzero(itoa_base(uld.uld.mant, 2), 63);
		if (uld.uld.exp == 32767)
		{
			infnan_proc(&flgs, sz, mant);
			return ;
		}
		else
			rf_proc(&flgs, sz, mant, uld);
	}
}
