/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:42:07 by jbouazao          #+#    #+#             */
/*   Updated: 2019/08/06 14:42:08 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_round(char *pow, int pnt, int pr)
{
    int i;
    int i2;
    char    *temp;
    char    *tmp;

    temp = pow;
    i = (int)ft_strlen(pow) - pnt + pr;
    ft_putnbr(i);
    ft_putendl("");
        ft_putendl(pow);
    if (pow[i] >= '5')
    {
        i2 = i + 1;
        if (pow[i] == '5')
            // while (pow[i2] == '0' && i2 < (int)ft_strlen(pow))
            while (pow[i2] == '0' && pow[i2])
                i2++;
        if (i2 < (int)ft_strlen(pow) || pow[i - 1] % 2 != 0 || pow[i] > '5')
        {
            temp = ft_strsub(pow, 0, i);
            tmp = temp;
            temp = str_add(tmp, "1");
        }
    }
    else
        temp = ft_strsub(pow, 0, i);
    return (temp);
}