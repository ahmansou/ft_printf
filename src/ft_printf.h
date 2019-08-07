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

# define ABS(x) ((x < 0) ? (-x) : (x))

typedef	struct		s_ld
{
	unsigned long	mant : 63;
	unsigned int	bit : 1;
	unsigned int	exp	: 15;
	unsigned int	sign : 1;
}					t_ld;


typedef struct	s_types
{
	char		types[11];
	void		(*t[11])(const char *frm, va_list ap, int *i, int *sz);
}				t_types;

typedef	struct s_flags
{
	int	mi;
	int plus; // '+' = +; '-' = -
	int space;
	int zero;
	int wd;
	int pr;
	int dot;
	int h; //0 1 2
	int l; //0 1 2
	int L;
	int oc;
}				t_flags;

t_types	get_types();

int				ft_printf(const char *format, ...);
void			get_params(const char *frm, va_list ap, int *i, int *sz);
void    		c_proc(const char *frm, va_list ap, int *i, int *sz);
void    		s_proc(const char *frm, va_list ap, int *i, int *sz);
void    		d_proc(const char *frm, va_list ap, int *i, int *sz);
void    		o_proc(const char *frm, va_list ap, int *i, int *sz);
void			u_proc(const char *frm, va_list ap, int *i, int *sz);
void			x_proc(const char *frm, va_list ap, int *i, int *sz);
void			p_proc(const char *frm, va_list ap, int *i, int *sz);
void			f_proc(const char *frm, va_list ap, int *i, int *sz);
void			get_flgs(const char *frm, t_flags *flgs, int *i, char c);
int				put_space(int sp_sz);
int				n_len(long long n);
int				put_zero(int z_sz);
long	long	get_va_arg(va_list ap, t_flags flgs);
unsigned long long get_va_arg_o(va_list ap, t_flags flgs);
char			*itoa_base(unsigned long long nbr, int base);
char			*str_add(char *a, char *b);
char			*str_mul(char *a, char *b);
char			*str_addzero(char *s1, char *s2);
char			*str_delzero(char *s);
char			*str_pow(char *a, int pow);
char			*mant_addzero(char *mant, int sz);
char	*str_addzeroback(char *s, int sz);
char    *ft_round(char *pow, int pnt, int pr);
int		print_f(char *pow, int lenp, int pnt, int pr);
int		print_fd(char *pow, int lenp, int pnt, int pr);
int     check_mant_zero(char *mant);