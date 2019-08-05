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
	char	*s;

	s = ft_strnew(ft_strlen(s1));
	s = ft_memset(s, 48, ft_strlen(s1) - ft_strlen(s2));
	s = ft_strcat(s, s2);
	free(s2);
	return (s);
}

char	*str_delzero(char *s)
{
	char 	*r;
	int		i;

	i = 0;
	while (s[i] == '0')
		i++;
	r = ft_strsub(s, i, ft_strlen(s) - i);
	return (r);
}