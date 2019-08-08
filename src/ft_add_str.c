/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:00:53 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/04 14:35:28 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_bzero_0(char *s, size_t n)
{
	char	*res;
	int		i;

	i = ft_strlen(s) - 1;
	res = ft_strnew(n);
	n = n - 1;
	while ((int)n >= 0)
	{
		if (i >= 0)
		{
			res[n] = s[i];
			i--;
		}
		else
			res[n] = '0';
		n--;
	}
	return (res);
}

static void	ft_swap(char *s1, char *s2)
{
	char	*temp;

	temp = s1;
	s1 = s2;
	s2 = temp;
}

static char	*ft_sub_add(char *s1, char *s2, size_t size)
{
	char			*res;
	unsigned int	rest;
	unsigned int	sum;
	size_t			i;

	sum = 0;
	i = 0;
	rest = 0;
	res = ft_strnew(size + 1);
	while (i < ft_strlen(s2))
	{
		sum = rest + ((s1[i] - '0') + (s2[i] - '0'));
		res[i++] = (sum % 10) + '0';
		rest = sum / 10;
	}
	while (i < ft_strlen(s1))
	{
		sum = rest + (s1[i] - '0');
		res[i++] = (sum % 10) + '0';
		rest = sum / 10;
	}
	res[i] = (rest != 0) ? rest + '0' : '0';
	return (res);
}

char	*ft_add_str(char *s1, char *s2)
{
	char	*res;

	if (ft_strlen(s1) < ft_strlen(s2))
		ft_swap(s1, s2);
	ft_strrev(s1);
	ft_strrev(s2);
	res = ft_sub_add(s1, s2, ft_strlen(s1));
	ft_strrev(res);
	return (res);
}
