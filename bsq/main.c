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

int		strlen_to_nl(char* str)
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

void foobar(char* filen)
{
    int fd;
    char* buff;
    int count;
    int fl_len;
    int str_count;
    int line_length;
    
    str_count = 0;
    buff = (char*)malloc(sizeof(char) * 42424243);
    buff[42424242] = '\0';
    fd = open(filen, O_RDONLY);
    if (fd <= 0)
        return (NULL);
    count = read(fd, buff, 42424242);
    if (count <= 0)
        return (NULL);
    fl_len = strlen_to_nl(buff);
    
    if(ft_len < 4)
        return (NULL);
    
    filler = buff[fl_len - 2];
    obstacle = buff[fl_len - 3];
    empty = buff[fl_len - 4];
    
    if(obstacle == empty)
        return (NULL);
    while((buff < buff + ft_len - 4))
    {
        if (buff >= '0' && buff <= '9')
            str_count = str_count * 10 + *buff - 48;
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
    line_length = strlen_to_nl(buff);
    
}

char** read_bsq(int fd, const int buff_size)
{
	char** map;
	char* str = malloc(sizeof(char) * (buff_size + 1));
	*(str + buff_size) = '\0';
	char* str_cp = str;
	int count;
	int lines_count;
	int line_length;
	int i;
	int j;
	char empty;
	char obstacle;
	char filler;

	i = 0;
	j = 0;
	lines_count = 0;
	count = read(fd, str, buff_size);

	if (count <= 0)
	{
		return (NULL);
	}
	while (*str >= '0' && *str <= '9')
	{
		lines_count = lines_count * 10 + *str - 48;
		str++;
	}
	if (lines_count == 0)
		return (NULL);

	empty = *str++;
	obstacle = *str++;
	filler = *str++;
	if (*str++ != '\n')
		return (NULL);
	line_length = strlen_to_n(str);
	map = (char**)malloc(sizeof(char*) * lines_count);
	char* line;

	while (i < lines_count)
	{
		line = (char*)malloc(sizeof(char) * (line_length));
		*(map + i) = line;
		while (j < line_length)
		{
			if (*str == '\0')
			{
				//	write(1, "need to read for more", 21);
				free(str_cp);
				str = malloc(sizeof(char) * (buff_size + 1));
				*(str + buff_size) = '\0';
				str_cp = str;
				count = read(fd, str, buff_size);
				//putnbr(count);
			}
			if (!(*str == '.' || *str == 'o'))
				return (NULL);
			*(line + j) = *str;
			str++;
			j++;
		}
		if (*str == '\0')
		{
			//	write(1, "need to read for more", 21);
			free(str_cp);
			str = malloc(sizeof(char) * (buff_size + 1));
			*(str + buff_size) = '\0';
			str_cp = str;
			count = read(fd, str, buff_size);
			//putnbr(count);
		}
		str++;
		j = 0;
		i++;
	}
	free(str_cp);

	i = 0;
	j = 0;

	int a = 10;
	int amax = 0;
	int x = 0;
	int y = 0;

	while (i < lines_count)
	{
		while (j < line_length)
		{
			if (*(*(map + i) + j) == obstacle)
			{

				int f = i;
				int s = j;
				while (f > i - a)
				{
					while (s > j - a)
					{
						if (*(*(map + f) + s) != 'o')
							*(*(map + f) + s) = 'x';
						s--;
						if (s < 0)
							break;
					}
					s = j;
					f--;
					if (f < 0)
						break;
				}

				*(*(map + i) + j) = 'o';
			}
			//write(1, "obst\n", 5);
			j++;
		}
		i++;
		j = 0;
	}



	i = 0;
	j = 0;
	while (i < lines_count)
	{
		write(1, *(map + i), line_length);
		write(1, "\n", 1);
		i++;
	}
}

int		main(void)
{
	/*int fd;
	fd = open("80x50.map", O_RDONLY);
	const int buffsize = 100;
	char** map = read_bsq(fd, buffsize);
	close(fd);*/

	//char* str;
	//str = (char*)malloc(sizeof(char) * 999483645);
	//str[12000111] = 'a';
	//str[5] = 'f';
	//str = str + 12000050;
	//int i = 0;

	//while (i < 1337)
	//{
	//	write(1, "f", 1);
	//	i++;
	//}
	char* filename = "80x50.map";
	foobar(filename);



	return (0);
}
