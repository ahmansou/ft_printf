/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_arithmetics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:24:01 by ahmansou          #+#    #+#             */
/*   Updated: 2019/08/04 14:24:02 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_addzero(char *s1, char *s2)
{
	char	*tmp;

	tmp = s2;
	s2 = ft_strnew(ft_strlen(s1) - ft_strlen(tmp));
	ft_memset(s2, '0', ft_strlen(s1) - ft_strlen(tmp));
	s2 = ft_strcat(s2, tmp);
	// free(tmp);
	return (s2);
}

char	*str_addzeroback(char *s, int sz)
{
	char	*tmp;

	tmp = s;
	s = ft_strnew(sz);
	ft_memset(s, '0', sz);
	s = ft_strcat(tmp, s);
	// free(tmp);
	return (s);
}

char	*str_delzero(char *s)
{
	int i;
	char *tmp;

	i = 0;
	while (s[i] == '0')
		i++;
	tmp = s;
	s = ft_strsub(tmp, i, ft_strlen(tmp) - i);
	return (s);
}