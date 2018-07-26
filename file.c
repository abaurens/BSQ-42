/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 04:06:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 01:29:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "errors.h"
#include "bsq.h"

char				is_valid(const char *s, const char *chst)
{
	int				i;

	if (chst && (*chst == chst[1] || chst[1] == chst[2] || *chst == chst[2]))
		return (0);
	while (s && *s)
	{
		i = 0;
		if (chst && *s == chst[2])
			return (0);
		while (chst && chst[i] && chst[i] != *s)
			i++;
		if (chst && !chst[i])
			return (0);
		if ((*s < '!' || *s > '~') && *s != '\n' && *s != '\t' && *s != ' ')
			return (0);
		s++;
	}
	return (1);
}

char				*read_line(const int fd)
{
	char			buff[2];
	char			*ret;
	char			*tmp;
	int				code;
	int				rd;

	code = 0;
	ret = NULL;
	buff[0] = '\0';
	buff[1] = '\0';
	while (*buff != '\n' && (rd = read(fd, buff, 1)) > 0)
	{
		if (!is_valid(buff, NULL))
			code = MAP_ERR_C;
		tmp = ret;
		if (code || (ret = ft_strmcat(ret, buff, -1)) == NULL)
		{
			free(tmp);
			ft_c_puterror(code ? code : MALLOC_ERR_C);
			return (NULL);
		}
		free(tmp);
	}
	return (ret);
}

char				*read_file(const int fd, const char *valid_chars)
{
	char			buff[READ_SIZE + 1];
	char			*ret;
	char			*tmp;
	int				rd;

	ret = NULL;
	while ((rd = read(fd, buff, READ_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (!is_valid(buff, valid_chars))
		{
			free(ret);
			ft_c_puterror(MAP_ERR_C);
			return (NULL);
		}
		tmp = ret;
		if ((ret = ft_strmcat(ret, buff, -1)) == NULL)
		{
			free(tmp);
			ft_c_puterror(MALLOC_ERR_C);
			return (NULL);
		}
		free(tmp);
	}
	return (ret);
}

t_errorc			convert_map(t_bsq *bsq)
{
	int				i;
	int				ln;
	char			*tmp;
	short			**ret;

	i = -1;
	ln = 0;
	ret = NULL;
	while (bsq && bsq->f_content && bsq->f_content[++i])
		if (bsq->f_content[i] == '\n')
			ln++;
	if (ln != bsq->h)
		return (MAP_ERR_C);
	if ((ret = malloc(sizeof(void *) * (ln + 1))) == NULL)
		return (MALLOC_ERR_C);
	ret[ln--] = NULL;
	while (--i >= 0)
	{
		tmp = bsq->f_content + i;
		if ((i == 0 || bsq->f_content[i - 1] == '\n') && bsq->f_content[i])
			if (!(ret[ln--] = compute_l(tmp, idx_of(tmp, '\n'), bsq->chars)))
				return (MALLOC_ERR_C);
	}
	bsq->map = ret;
	return (NO_ERR_C);
}

void				delete_bsq(t_bsq *bsq)
{
	int				i;

	i = 0;
	free(bsq->chars);
	free(bsq->f_content);
	while (bsq->map && bsq->map[i])
		free(bsq->map[i++]);
	free(bsq->map);
}
