/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:44:35 by hvayne            #+#    #+#             */
/*   Updated: 2020/02/25 08:23:11 by hvayne           ###   ########.fr       */
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

int		strlen_to_n(char *str)
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

void	read_bsq(int fd, int buff_size)
{
	char str[buff_size];
	int count;
	int lines_count;
	int i;

	i = 0;
	count = read(fd, str, buff_size);
	while (str[i] >= '0' && str[i] <= 9)
	{
		lines_count = lines_count * 10 + str[i] - 48;
	}
	putnbr(lines_count);
}

int		main(void)
{
	int fd;
	fd = open("square.map", O_RDONLY);
	read_bsq(fd, 8192);
	close (fd);
	return (0);
}
