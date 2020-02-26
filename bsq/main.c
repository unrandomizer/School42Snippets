/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:44:35 by hvayne            #+#    #+#             */
/*   Updated: 2020/02/26 16:16:27 by hvayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_bsq.h"


info* get_info(char** buff)
{
	int fl_len;
	info* map_info;

	map_info = (info*)malloc(sizeof(info));
	fl_len = strlen_to_nl(buff[0]);
	if (fl_len < 4)
		return (NULL);
	map_info->filler = buff[0][fl_len - 1];
	map_info->obstacle = buff[0][fl_len - 2];
	map_info->empty = buff[0][fl_len - 3];
	map_info->line_count = 0;
	if (map_info->obstacle == map_info->empty)
		return (NULL);
	char* buff_cpy = buff[0];
	while ((buff[0] < buff_cpy + fl_len - 3))
	{
		if (*buff[0] >= '0' && *buff[0] <= '9')
			map_info->line_count = map_info->line_count * 10 + *buff[0] - 48;
		else
		{
			return (NULL);
		}
		buff[0]++;
	}
	while (*buff[0] != '\n')
		buff[0]++;
	buff[0]++;
	map_info->line_len = strlen_to_nl(buff[0]);
	return (map_info);
}
ecell add_ecell(ecell head, int value)
{
    ecell temp;
    ecell p;
    
    temp = (ecell)malloc(sizeof(ecell));
    temp->cellid = value;
    p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}

char foobar(int fd)
{
	char* buff;
    char* buff_cp;
	int count;
	info* map_info;
    ecell *ecell_list;
    ecell *ecell_tmp;

	buff = (char*)malloc(sizeof(char) * 42424243);
    buff_cp = buff;
	buff[42424242] = '\0';
	count = read(fd, buff, 42424242);
	if (count <= 0)
		return (0);
	map_info = get_info(&buff);
    while (*buff)
    {
        ecell_tmp = (ecell*)malloc(sizeof(ecell));
        while(42)
        {
            ecell_list
        }
        buff++;
    }
    return (1);
}

int		main(int argc, char** argv)
{
	int fd;
	if (argc == 1)
	{
		// map with stdin implementation
	}
	else 
	{
		char* filename = argv[1];
		fd = open(filename, O_RDONLY);
		if (fd <= 0)
		write(2, "map 1error\n", 10);
		foobar(fd);

	}
	return (0);
}
