/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:31:51 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/13 19:32:01 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	precf(const char *frm, int i)
{
	int prec;
	
	prec = 0;
	while(frm[i] != '.' && frm[i] && frm[i] != 's')
		i++;
	if (frm[i] == '.')
		i++;
	else
		return (0);
	if (frm[i] >= '1' && frm[i] <= '9')
		prec = ft_atoi(&frm[i]);
	return (prec);
}

void			s_proc(const char *frm, va_list ap, int *i, int *sz)
{
	char	*s;
	char	*tmp;
	int		indx;
	int		prec;
	int		must_free;

	s = va_arg(ap, char*);
	indx = *i;
	must_free = 0;
	if (!s && (must_free = 1))
		s = ft_strdup("(null)");
	if ((prec = precf(frm, *i)))
	{
		(must_free == 1 && (tmp = s)) ? free(tmp) : ft_putstr("");
		s = ft_strsub(s, 0, prec);
		must_free = 1;
	}
	(frm[indx] == '-' && (*i)++) ? ft_putstr(s) : ft_putstr("");
	if (frm[*i] >= '1' && frm[*i] <= '9')
		*sz += put_space(ft_atoi(&frm[*i]) - ft_strlen(s));
	(frm[indx] != '-' && (*i)++) ? ft_putstr(s) : ft_putstr("");
	(must_free == 1) ? free(s) : ft_putstr("");
	(*sz) += ft_strlen(s);
}