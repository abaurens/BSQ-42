/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:30:31 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 03:43:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "errors.h"
#include "bsq.h"

void			manage_tab(t_bsq *bsq)
{
	int			x;
	int			y;
	int			top;
	int			left;
	int			diag;

	y = -1;
	bsq->s.size = 0;
	while (bsq && bsq->map && bsq->map[++y])
	{
		x = -1;
		while (bsq->map[y][++x] != -2)
		{
			top = (x == 0 ? 0 : bsq->map[y][x - 1]);
			left = (y == 0 ? 0 : bsq->map[y - 1][x]);
			diag = ((x == 0) || (y == 0) ? 0 : bsq->map[y - 1][x - 1]);
			bsq->map[y][x] *= min(min(top, left), diag) + 1;
			if (bsq->s.size < bsq->map[y][x])
			{
				bsq->s.x = x;
				bsq->s.y = y;
				bsq->s.size = bsq->map[y][x];
			}
		}
	}
}

void			place_square(t_bsq *bsq)
{
	int			x;
	int			y;
	int			p;
	t_square	sq;

	sq = bsq->s;
	sq.x -= (sq.size - 1);
	sq.y -= (sq.size - 1);
	y = 0;
	while (y < sq.size)
	{
		x = 0;
		while (x < sq.size)
		{
			p = ((sq.x + x) + (sq.y + y) * (bsq->w + 1));
			bsq->f_content[p] = bsq->chars[2];
			x++;
		}
		y++;
	}
}

t_errorc		bsq(const char *file)
{
	t_errorc	error;
	t_bsq		bsq;
	int			fd;

	fd = 0;
	if (file && (fd = open(file, O_RDONLY)) < 0)
		return (F_OPN_ERR_C);
	if (!(error = get_bsq(fd, &bsq)))
	{
		manage_tab(&bsq);
		place_square(&bsq);
		ft_putstr(bsq.f_content);
		delete_bsq(&bsq);
	}
	if (fd > 0 && close(fd) < 0)
		return (F_CLS_ERR_C);
	return (error);
}
