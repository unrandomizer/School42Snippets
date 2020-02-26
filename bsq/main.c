/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:44:35 by hvayne            #+#    #+#             */
/*   Updated: 2020/02/26 04:31:46 by hvayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
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

int		strlen_to_n(char* str)
{
	int len;

	len = 0;
	while (*str != '\n' || *str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

char** read_bsq(int fd, const int buff_size)
{
	char** map;
	char* str = malloc(sizeof(char) * 21042);
	int count;

	int lines_count;
	int i;
	int j;

	i = 0;
	j = 0;
	lines_count = 0;
	count = read(fd, str, buff_size);
	
	if (count <= 0)
	{
		return (NULL);
	}
	while(*str >= '0' && *str <= '9')
	{
		lines_count = lines_count * 10 + *str;
		str++;
	}
	putnbr(lines_count);
	return (NULL);
	/*
	while (42)
	{
		while (21)
		{
			if (*str == '\n')
				break;
			if (*str == '\0')
				break;
			str++;
		}
		str++;
		while (i < 8)
		{
			while (j < 12)
			{
				if (!(*str == '.' || *str == 'o'))
					return (NULL);
				map[i][j] = *str;
				str++;
				j++;
			}
			str++;
			j = 0;
			i++;
		}
	}
	free(str);*/
}

int		main(void)
{
	int fd;
	fd = open("12x08.map", O_RDONLY);
	const int buffsize = 8192;
	char** map = read_bsq(fd, buffsize);
	close(fd);
	return (0);
}
