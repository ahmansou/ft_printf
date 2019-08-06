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

union	u_ld
{
	long double	ld;
	t_ld		uld;
};


static	long double get_va_arg_f(va_list ap, t_flags flgs)
{
	if (flgs.L == 1)
		return (va_arg(ap, long double));
	else
		return ((long double)va_arg(ap, double));
}

static char *conv_mant(char *mant, int exp)
{
	int		i;
	char	*a;
	char	*pw;

	i = 0;
	a = ft_strnew(1);
	(exp = 0) ? ft_memset(a, '0', 1) : ft_memset(a, '1', 1);
	while (mant[i])
	{
		a = str_mul(a, "10");
		if (mant[i] == '1')
		{
			pw = str_pow("5", i + 1);
			a = str_add(a, pw);
			free(pw);
		}
		i++;
	}
	return (a);
}

void			f_proc(const char *frm, va_list ap, int *i, int *sz)
{
	long double	ld;
	int			pnt;
	char		*mant;
	char		*pow;
	t_flags		flgs;
	union u_ld	uld;
	int			indx;
	int 		lenp;

	get_flgs(frm, &flgs, i, 'f');
	// printf("\nmi : %d, plus : %d, space : %d, zero : %d, wd : %d, pr : %d, dot : %d, h : %d, l : %d,  L : %d \n",
	// flgs.mi, flgs.plus, flgs.space, flgs.zero, flgs.wd, flgs.pr, flgs.dot, flgs.h, flgs.l, flgs.L);
	// ld = va_arg(ap, long double);
	ld = get_va_arg_f(ap, flgs);
	uld.ld = ld;
	mant = mant_addzero(itoa_base(uld.uld.mant, 2), 63);
	mant = conv_mant(mant, uld.uld.exp);
	if (uld.uld.exp - 16383 < 0)
	{
		pow = str_pow("5", ABS(uld.uld.exp - 16383));
		pnt = ABS(uld.uld.exp - 16383) + 63;
	}
	else
	{
		pow = str_pow("2", ABS(uld.uld.exp - 16383));
		pnt = 63;
	}
	pow = str_mul(pow, mant);
	pow = str_delzero(pow);
	lenp = (int)ft_strlen(pow);
	if (flgs.pr < pnt && flgs.pr)
		// printf("%s\n", ft_round(pow, pnt, flgs.pr));
		pow = ft_round(pow, pnt, flgs.pr);
	pow = str_delzero(pow);
	indx = 0;
	// ft_printf("%d, %d, %d\n", pnt, flgs.pr, (int)ft_strlen(pow));
	while (indx < lenp - pnt)
		ft_putchar(pow[indx++]);
	ft_putchar('.');
	while (pow[indx])
		ft_putchar(pow[indx++]);
	*sz += 0;
}

// 0b11111111111111 = 16383
// 042256000000000000227373675443232059478759765625000000000000000000
