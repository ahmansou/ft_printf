/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:57:55 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/13 19:09:07 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

typedef struct	s_types
{
	char		types[4];
	void		(*t[4])(const char *frm, va_list ap, int *i, int *sz);
}				t_types;

t_types	get_types();

int		ft_printf(const char *format, ...);
void	get_params(const char *frm, va_list ap, int *i, int *sz);
void    c_proc(const char *frm, va_list ap, int *i, int *sz);
void    s_proc(const char *frm, va_list ap, int *i, int *sz);
void    d_proc(const char *frm, va_list ap, int *i, int *sz);
int		put_space(int sp_sz);
int		n_len(int n);