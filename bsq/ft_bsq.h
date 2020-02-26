/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:05:54 by hvayne            #+#    #+#             */
/*   Updated: 2020/02/26 16:14:10 by hvayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_info
{
	int line_len;
	int line_count;
	char empty;
	char obstacle;
	char filler;
}					info;

typedef struct      s_ecell
{
    int             cellid;
    struct s_ecell  *next;
}                   ecell;

void				putnbr(int nbr);
void				putstr(char *str);
int					strlen_to_nl(char *str);
#endif
