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

static	void	set_flg(int *nf)
{
	int i;

	i = 0;
	while (i < 6)
		nf[i++] = 0;
}

static	void	get_flg1(const char *frm, int *nf, int i)
{
	while (!(frm[i] >= '0' && frm[i] <= '9') && frm[i] != 'd')
	{
		if (frm[i] ==  '-')
			nf[0] = 1;
		else if (frm[i] ==  '+')
			nf[1] = 1;
		else if (frm[i] ==  ' ')
			nf[2] = 1;
		i++;
	}
}

static	void	get_flgwp(const char *frm, int *nf, int i)
{
	while (frm[i] != '0' && frm[i] != 'd' && frm[i] != '.' &&
		!(frm[i] >= '1' && frm[i] <= '9'))
		i++;
	nf[3] =  (frm[i] ==  '0') ? 1 : 0;
	while (frm[i] == '0' && frm[i] != 'd')
		i++;
	nf[4] = (frm[i] >= '1' && frm[i] <= '9' &&
			frm[i] != 'd') ? ft_atoi(&frm[i]) : 0;
	while (frm[i] != '.' && frm[i] != 'd')
		i++;
	nf[5] = (frm[i] == '.') ? ft_atoi(&frm[i + 1]) : 0;
}

/*	flags : 0 = '-', 1 = '+', 2 = ' ', 3 = '0', 4 = width, 5 = prec	*/
void	d_proc(const char *frm, va_list ap, int *i, int *sz)
{
	int		d;
	char	*t;
	int		nf[6];
	int		mf;

	d = va_arg(ap, int);
	mf = 0;
	set_flg(nf);
	get_flg1(frm, nf, *i);
	get_flgwp(frm, nf, *i);
	d = (nf[5]) ? ft_atoi(t = ft_strsub(ft_itoa(d), 0 * (mf = 1), nf[5])) : d;
	(mf) ? free(t) : ft_putstr("");
	if (nf[0])
	{
		nf[3] = 0;
		if (nf[1] && !(nf[2] = 0))
		{
			ft_putchar('+');
			nf[4] -= 1;
			*sz += 1;
		}
		else
			if (nf[4] > 0)
				nf[4] -= (nf[2]) ? 1 : 0;
		ft_putnbr(d);
		if (nf[4] > 0)
			nf[4] -= n_len(d);
		sz += put_space(nf[4]);
	}
	// if (!nf[0])
	// {
	// 	if (nf[1] && !(nf[2] = 0))
	// 	{
	// 		ft_putchar('+');
	// 		nf[4] -= 1;
	// 		*sz += 1;
	// 	}
	// 	else
	// 		nf[4] -= (nf[2]) ? 1 : 0;
	// 	// if (nf[3])
	// 	// {
	// 	// 	if (nf[4] > 4)

	// 	// }
	// 	ft_putnbr(d);
	// }
	// ft_putnbr(d);
	*sz += n_len(d);
}