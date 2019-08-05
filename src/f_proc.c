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

static char *conv_mant(char *mant)
{
	int		i;
	char	*a;
	char	*pw;

	i = 0;
	a = ft_strnew(1);
	ft_memset(a, '0', 1);
	while (mant[i])
	{
		if (mant[i] == '1')
		{
			a = str_mul(a, "10");
			// ft_printf("%s + ", a);
			pw = str_pow("5", i + 1);
			a = str_add(a, pw);
			free(pw);
			// ft_printf("%c * 5 ^ %d = %s\n", mant[i], i + 1, a);
			// ft_printf("%s\n", a);
		}
		i++;
	}
	return (a);
}

void			f_proc(const char *frm, va_list ap, int *i, int *sz)
{
	long double	ld;
	double		d;
	char		*mant;
	t_flags		flgs;
	union u_d	ud;
	union u_ld	uld;

	get_flgs(frm, &flgs, i, 'f');
	// printf("\nmi : %d, plus : %d, space : %d, zero : %d, wd : %d, pr : %d, dot : %d, h : %d, l : %d,  L : %d \n",
	// flgs.mi, flgs.plus, flgs.space, flgs.zero, flgs.wd, flgs.pr, flgs.dot, flgs.h, flgs.l, flgs.L);
	if (flgs.L)
	{
		ld = va_arg(ap, long double);
		uld.ld = ld;
		mant = mant_addzero(itoa_base(uld.uld.mant, 2), 63);
		ft_printf("\nmantissa : %lu - %s\nexp      : %u\n",
		uld.uld.mant, mant, uld.uld.exp);
		printf("%Lf", uld.ld);
	}
	else
	{
		d = va_arg(ap, double);
		ud.d = d;
		printf("%lf", ud.d);
		mant = mant_addzero(itoa_base(ud.ud.mant, 2), 52);
		ft_printf("\nmantissa : %lu - %s\nexp      : %u\n",
		ud.ud.mant, mant, ud.ud.exp);
		mant = conv_mant(mant);
		ft_printf("%s", mant);
	}
	*sz += 0;
}
// 0101001000001100010010011011101001011110001101010100
// 0101001000001100010010011011101001011110001101010100
// 02775557561544701457023620605468750000