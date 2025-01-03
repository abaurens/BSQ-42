/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:32:11 by abaurens          #+#    #+#             */
/*   Updated: 2025/01/03 01:52:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "types.h"
# include "errors.h"

# define READ_SIZE 8192
# define CHARSET_SIZE 3

typedef struct
{
  short x;
  short y;
  short size;
} t_square;

typedef struct
{
  short     w;
  short     h;
  short     *max;
  char      charset[CHARSET_SIZE + 1];
  char      *map;
  short     *matrix;
} t_bsq;

/*
**  loading.c
*/
void  place_square(t_bsq *const bsq);
t_errorc find_square(t_bsq *const bsq);

/*
**  bsq.c
*/
t_errorc  get_bsq(int fd, t_bsq *const bsq);
t_errorc  find_square(t_bsq *const bsq);
void      place_square(t_bsq *const bsq);

/*
**  utils.c
*/
int   ft_atolu(char *str);
int   ft_strlen(const char *const str);
void  ft_bzero(void *const ptr, size_t size);
int   idx_of(const char *const str, char c);
char  contains(const char *const str, char c);

/*
**  print.c
*/
void  ft_putchar(char c);
void  ft_putstr(char *str);
void  ft_putnbr(int number, int length);

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#endif
