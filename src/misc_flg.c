/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_flg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:42:43 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/18 09:42:45 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	set_flgs(t_flags *flgs)
{
	flgs->minus = 0;
	flgs->plus = 0;
	flgs->space = 0;
	flgs->zero = 0;
	flgs->width = 0;
	flgs->prec = 0;
	flgs->dot = 0;
	flgs->h = 0;
	flgs->l = 0;
}

static	void	get_hl(const char *frm, t_flags *flgs, int *i)
{
	while (frm[*i] != 'd')
		(*i)++;
	if (frm[*i - 1] == 'h')
		flgs->h = (frm[*i - 2] == 'h') ? 2 : 1;
	else if (frm[*i - 1] == 'l')
		flgs->l = (frm[*i - 2] == 'l') ? 2 : 1;
}

// static	void	get_mps(const char *frm, t_flags *flgs, int *i)
// {

// }

void			get_flgs(const char *frm, t_flags *flgs, int *i)
{
	set_flgs(flgs);
	while (!(frm[*i] >= '0' && frm[*i] <= '9') &&
			frm[*i] != '.' && frm[*i] != 'd' &&
			frm[*i] != 'h' && frm[*i] != 'l')
	{
		if (frm[*i] == '-')
			flgs->minus = 1;
		else if (frm[*i] == '+')
			flgs->plus = '+';
		else if (frm[*i] == ' ')
			flgs->space = 1;
		(*i)++;
	}
	flgs->zero = (frm[*i] == '0') ? 1 : 0;
	while (frm[*i] == '0')
		(*i)++;
	flgs->width = (frm[*i] >= '1' && frm[*i] <= '9' &&
			frm[*i] != 'd') ? ft_atoi(&frm[*i]) : 0;
	while (frm[*i] != '.' && frm[*i] != 'd' &&
			frm[*i] != 'h' && frm[*i] != 'l')
		(*i)++;
	flgs->prec = (frm[*i] == '.') ? ft_atoi(&frm[*i + 1]) : 0;
	flgs->dot = (frm[*i] == '.') ? 1 : 0;
	get_hl(frm, flgs, i);
}
