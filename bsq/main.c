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
#include <time.h>
#include <stdio.h>

typedef struct s_info
{
	int line_len;
	int line_count;
	char empty;
	char obstacle;
	char filler;
}				info;

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

int	strlen_to_nl(char* str)
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

info* get_info(char* buff)
{
	int fl_len;
	info* map_info;

	map_info = (info*)malloc(sizeof(info));
	fl_len = strlen_to_nl(buff);
	if (fl_len < 4)
		return (NULL);
	map_info->filler = buff[fl_len - 1];
	map_info->obstacle = buff[fl_len - 2];
	map_info->empty = buff[fl_len - 3];
	map_info->line_count = 0;
	if (map_info->obstacle == map_info->empty)
		return (NULL);
	char* buff_cpy = buff;
	while ((buff < buff_cpy + fl_len - 3))
	{
		if (*buff >= '0' && *buff <= '9')
			map_info->line_count = map_info->line_count * 10 + *buff - 48;
		else
		{
			return (NULL);
		}
		buff++;
	}
	while (*buff != '\n')
		buff++;
	buff++;
	// we are on the first line	
	map_info->line_len = strlen_to_nl(buff);
	return (map_info);
}

void foobar(int fd)
{

	char* buff;
	int count;
	int fl_len;
	info* map_info;

	buff = (char*)malloc(sizeof(char) * 42424243);
	buff[42424242] = '\0';
	count = read(fd, buff, 42424242);
	if (count <= 0)
		return (NULL);
	map_info = get_info(buff);
	if (map_info == NULL)
		write(2, "map error\n", 10);
}

int		main(void)
{
	int fd;
	char* filename = "80x50.map";
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		write(2, "map error\n", 10);
	foobar(fd);

	return (0);
}
