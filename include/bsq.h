/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:32:11 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 01:32:25 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "errors.h"

# define READ_SIZE 8192

typedef struct	s_square
{
	short		x;
	short		y;
	short		size;
}				t_square;

typedef struct	s_bsq
{
	short		w;
	short		h;
	char		*chars;
	char		*f_content;
	short		**map;
	t_square	s;
}				t_bsq;

/*
**	file.c
*/
void			delete_bsq(t_bsq *bsq);
char			*read_line(const int fd);
t_errorc		convert_map(t_bsq *bsq);
char			*read_file(const int fd, const char *valid_chars);

/*
**	bsq.c
*/
t_errorc		bsq(const char *file);

/*
**	s_string.c
*/
int				ft_strlen(const char *str);
int				idx_of(const char *str, const char c);
char			contains(const char *str, const char c);

/*
**	m_string.c
*/
void			ft_replace(char *str, const char c, const char d);
char			*ft_strmcat(const char *s1, const char *s2, int l);
short			*compute_l(const char *tmp, short l, const char *charset);

/*
**	parsing.c
*/
t_errorc		get_bsq(const int fd, t_bsq *bsq);

/*
**	parsing_utils.c
*/
int				num_len(int nb);
int				ft_atoi(char *str);

/*
**	print.c
*/
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			print_bsq(t_bsq *bsq);

/*
**	math.c
*/
int				min(int x, int y);

#endif
