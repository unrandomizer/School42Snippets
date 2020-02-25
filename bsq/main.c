/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:44:35 by hvayne            #+#    #+#             */
/*   Updated: 2020/02/25 07:34:20 by hvayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

void putstr(char *str)
{
	while(*str)
	{
		write(1, str++, 1);
	}
}

void strlen_to_n(char *str)
{
	int len;

	len = 0;
	while(*str != '\n' || *str != '\0')
	{
		len++;
		str++;
	}	
	return len;
}

int		main(void)
{
	int fd;
	short BUFF_SIZE = 8192;
	char c;
	char str[BUFF_SIZE];
	int count;

	fd = open("square.map", O_RDONLY);
	while ((count = read(fd, str, BUFF_SIZE)))
	{
	    putnbr(count);
	    write(1, "\n", 1);
		putstr(str);
	}
	close (fd);
	return (0);
}
