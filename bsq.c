/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:30:31 by abaurens          #+#    #+#             */
/*   Updated: 2025/01/03 01:53:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "types.h"
#include "bsq.h"

/**
 ** @brief Get the value of the current cell at position i in the matrix
 ** 
 ** @param bsq The current BSQ instance
 ** @param i The position of the matrix cell for which we want to get the value
 ** @param cell The ASCII value of the cell
 */
static short get_cell_value(const t_bsq *const bsq, int i, char cell)
{
  int   above;
  short a;
  short b;
  short c;

  if (cell == bsq->charset[1])
    return 0;

  if (bsq->w == 0 || (i % bsq->w) == 0)
    return 1;
  
  above = i - bsq->w;
  a = bsq->matrix[i - 1];
  b = bsq->matrix[above];
  c = bsq->matrix[above - 1];
  return 1 + MIN(a, MIN(b, c));
}

/**
 ** @brief Set the value of the matrix cell represented by `i` and
 ** update the saved square position if needed
 **
 ** @param bsq The current BSQ instance
 ** @param i The position of the matrix cell for which we want to set the value
 ** @param cell The ASCII value of the cell
 */
static void process_cell(t_bsq *const bsq, int i, char cell)
{
  const short value = get_cell_value(bsq, i, cell);

  bsq->matrix[i] = value;
  if (!bsq->max || *bsq->max < value)
    bsq->max = bsq->matrix + i;
}

/**
 ** @brief Validate and search for the bigest square in the map
 **
 ** @param bsq The current BSQ instance
 */
t_errorc find_square(t_bsq *const bsq)
{
  int   i;
  short h;
  char  *ptr;

  i = 0;
  h = 0;
  ptr = bsq->map;
  while (*ptr != 0)
  {
    if (*ptr == '\n')
    {
      ++h;
      ++ptr;
      if (!bsq->w)
        bsq->w = i;
      else if ((i % bsq->w) != 0)
        return (MAP_ERR_C);
      continue;
    }
    if (!contains(bsq->charset, *ptr) || *ptr == bsq->charset[2])
      return (MAP_ERR_C);
    process_cell(bsq, i++, *ptr);
    ++ptr;
  }
  return (h == bsq->h ? NO_ERR_C : MAP_ERR_C);
}

/**
 ** @brief Place the square into the map's ASCII representation
 **
 ** @param bsq The current BSQ instance
 */
void  place_square(t_bsq *const bsq)
{
  const int i = bsq->max - bsq->matrix;
  t_square sq;
  short x;
  short y;
  int   p;

  sq.x = i % bsq->w;
  sq.y = i / bsq->w;
  sq.size = *bsq->max;
  y = 0;
  while (y < sq.size)
  {
    x = 0;
    while (x < sq.size)
    {
      p = ((sq.x - x) + (sq.y - y) * (bsq->w + 1));
      bsq->map[p] = bsq->charset[2];
      x++;
    }
    y++;
  }
}
