/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:14:46 by hvayne            #+#    #+#             */
/*   Updated: 2020/02/26 16:16:48 by hvayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void putnbr(int nbr)
{
    char c;
    
    if (nbr <= 9)
    {
        c = nbr + 48;
        write(1, &c, 1);
    }
    else
    {
        putnbr(nbr / 10);
        putnbr(nbr % 10);
    }
}

void putstr(char* str)
{
    while (*str)
    {
        write(1, str++, 1);
    }
}

int    strlen_to_nl(char* str)
{
    int len;
    
    len = 0;
    while (!(*str == '\n' || *str == '\0'))
    {
        len++;
        str++;
    }
    return len;
}
