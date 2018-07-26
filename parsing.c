/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 02:54:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 22:11:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "errors.h"
#include "bsq.h"

static t_errorc	check_lines(t_bsq *bsq)
{
	int			i;
	int			l;

	i = -1;
	bsq->w = 0;
	if (bsq->h <= 0)
		return (MAP_ERR_C);
	while (bsq && bsq->map && bsq->map[++i])
	{
		l = 0;
		while (bsq->map[i][l] != -2)
			l++;
		if (bsq->w == 0)
			bsq->w = l;
		if (l != bsq->w)
			return (MAP_ERR_C);
	}
	if (bsq->w == 0)
		return (MAP_ERR_C);
	return (NO_ERR_C);
}

static t_errorc	parse_file(const int fd, t_bsq *bsq)
{
	int			i;

	if ((bsq->f_content = read_line(fd)) == NULL)
		return (ALREADY_MANAGED);
	if ((bsq->h = ft_strlen(bsq->f_content) - 4) < 1)
		return (MAP_ERR_C);
	i = bsq->h;
	while (bsq->f_content[bsq->h + ++i + 1])
		if (contains(&bsq->f_content[i + 1], bsq->f_content[i]))
			return (MAP_ERR_C);
	bsq->chars = ft_strmcat(&bsq->f_content[bsq->h], NULL, -1);
	bsq->f_content[bsq->h] = 0;
	if ((bsq->h = ft_atoi(bsq->f_content)) <= 0)
		return (MAP_ERR_C);
	free(bsq->f_content);
	if (ft_strlen(bsq->chars) != 4)
		return (MAP_ERR_C);
	if ((bsq->f_content = read_file(fd, bsq->chars)) == NULL)
		return (ALREADY_MANAGED);
	return (0);
}

t_errorc		get_bsq(const int fd, t_bsq *bsq)
{
	int			i;
	t_errorc	ret;
	t_errorc	(*funcs[2])(t_bsq *);

	i = 0;
	ret = NO_ERR_C;
	funcs[0] = convert_map;
	funcs[1] = check_lines;
	ret = parse_file(fd, bsq);
	while (!ret && i < 2)
		ret = funcs[i++](bsq);
	return (ret);
}
