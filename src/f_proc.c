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
#include "float.h"

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
		a = ft_mult_str(a, "10", 1);
		//ft_printf("10 * %s + 5 ^ %d = ", a, i + 1);
		if (mant[i] == '1')
		{
			pw = str_pow("5", i + 1);
			a = ft_add_str(a, pw);
			//ft_printf("%s\n", a);
			free(pw);
		}
		i++;
	}
	// printf("--->%s\n", a);
	return (a);
}

static	void	z_proc(t_flags *flgs, int *sz)
{
	char	*z;

	if (!flgs->pr && flgs->dot && !flgs->oc)
		z = ft_strdup("0");
	else
		z = ft_strdup("0.");
	flgs->pr = (!flgs->pr && !flgs->dot) ? 6 : flgs->pr;
	flgs->wd -= (flgs->plus || flgs->space) ? 1 : 0;
	*sz += (flgs->wd && !flgs->zero && !flgs->mi) ? 
		put_space(flgs->wd - flgs->pr - ft_strlen(z)) : 0;
	if (flgs->plus)
		*sz += write(1, &flgs->plus, 1);
	else if (flgs->space)
		*sz += write(1, " ", 1);
	*sz += (flgs->zero && !flgs->mi) ?
		put_zero(flgs->wd - flgs->pr - ft_strlen(z)) : 0;
	ft_putstr(z);
	*sz +=  ft_strlen(z);
	*sz += put_zero(flgs->pr);
	*sz += (flgs->mi) ? put_space(flgs->wd - flgs->pr - ft_strlen(z)) : 0;
	free(z);
}

static	void	infnan_proc(t_flags *f, int *sz, char *mant)
{
	char	*inf;
	int		isinf;

	isinf = 0;
	if (check_mant_zero(mant) && (isinf = 1))
		inf = ft_strdup("inf");
	else
		inf = ft_strdup("nan");
	f->wd -= (isinf && (f->plus || f->space)) ? 1 : 0; 
	*sz += (!f->mi && f->wd) ? put_space(f->wd - ft_strlen(inf)) : 0 ;
	if (f->plus && isinf)
		*sz += write(1, &f->plus, 1);
	else if (f->space && isinf)
		*sz += write(1, " ", 1);
	ft_putstr(inf);
	*sz += ft_strlen(inf);
	*sz += (f->mi && f->wd) ? put_space(f->wd - ft_strlen(inf)) : 0 ;
}

static	void	rrf_proc(t_flags *f, int *sz, char *pow, int lp[])
{
	char *tmp;

	f->pr = (!f->pr && !f->dot) ? 6 : f->pr;
	if (f->pr < lp[0])
	{
		tmp = pow;
		pow = ft_round(pow, lp[0], f->pr);
		pow = str_delzero(pow);
		free(tmp);
	}
	f->wd -= (f->dot && f->dot && !f->oc && !f->pr) ? 1 : 0;
	f->wd -= (f->plus || f->space) ? 1 : 0;
	*sz += (f->wd && !f->zero && !f->mi) ?
		put_space(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
	if (f->plus)
		*sz += write(1, &f->plus, 1);
	else if (f->space)
		*sz += write(1, " ", 1);
	*sz += (f->wd && f->zero && !f->mi) ?
		put_zero(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
	*sz += ((!(f->dot && !f->pr) || f->oc)) ?
		print_fd(pow, lp[1], lp[0], f->pr) : print_f(pow, lp[1], lp[0], f->pr);
	*sz += (f->mi && f->wd) ? put_space(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
}

static	void	subone_proc(t_flags *f, int *sz, char *pow, int lp[])
{
	char *tmp;

	f->pr = (!f->pr && !f->dot) ? 6 : f->pr;
	if (f->pr < lp[0])
	{
		tmp = pow;
		pow = ft_round(pow, lp[0], f->pr);
		free(tmp);
	}
	f->wd -= (f->dot && f->dot && !f->oc && !f->pr) ? 1 : 0;
	f->wd -= (f->plus || f->space) ? 1 : 0;
	*sz += (f->wd && !f->zero && !f->mi) ?
		put_space(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
	if (f->plus)
		*sz += write(1, &f->plus, 1);
	else if (f->space)
		*sz += write(1, " ", 1);
	*sz += (f->wd && f->zero && !f->mi) ?
		put_zero(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
	*sz += ((!(f->dot && !f->pr) || f->oc)) ?
		print_fd(pow, lp[1], lp[0], f->pr) : print_f(pow, lp[1], lp[0], f->pr);
	*sz += (f->mi && f->wd) ? put_space(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
}

static	void	rf_proc(t_flags *f, int *sz, char *mant, union u_ld ld)
{
	int			lp[2];
	char		*pow;
	char		*tmp;

	mant = conv_mant(mant, ld.uld.exp);
	if (ld.uld.exp - 16383 < 0 && (lp[0] = ((ld.uld.exp - 16383) * -1) + 63))
	{

		pow = str_pow("5", (ld.uld.exp - 16383) * -1);
	}
	else
	{
		pow = str_pow("2", ld.uld.exp - 16383);
		lp[0] = 63;
	}
	pow = str_mul(pow, mant);
	// ft_putendl(pow);
	if (!(ld.ld > 0 && ld.ld < 1))
		pow = str_delzero(pow);
	lp[1] = (int)ft_strlen(pow);
	if (ld.ld > 0 && ld.ld < 1)
	{
		// ft_printf("\n%d\n", f->pr - ft_strlen(pow));
		tmp = ft_strnew(f->pr - ft_strlen(pow));
		ft_memset(tmp, '0', f->pr - ft_strlen(pow));
		pow = ft_strjoin(tmp, pow);
		subone_proc(f, sz, pow, lp);
	}
	else
		rrf_proc(f, sz, pow, lp);
}

void			f_proc(const char *frm, va_list ap, int *i, int *sz)
{
	long double	ld;
	char		*mant;
	t_flags		flgs;
	union u_ld	uld;

	get_flgs(frm, &flgs, i, 'f');
	ld = get_va_arg_f(ap, flgs);
	// if (ld == DBL_MIN || ld == 0.000099)
	// 	return ;
	uld.ld = ld;
	if (uld.uld.sign)
		flgs.plus = '-';
	if (ld == 0)
		z_proc(&flgs, sz);
	else
	{
		// printf("%lu\n", uld.uld.mant);
		// printf("%s\n", itoa_base(uld.uld.mant, 2));
		mant = mant_addzero(itoa_base(uld.uld.mant, 2), 63);
		// ft_putendl(mant);
		if (uld.uld.exp == 32767)
		{
			infnan_proc(&flgs, sz, mant);
			return ;
		}
		rf_proc(&flgs, sz, mant, uld);
	}
}