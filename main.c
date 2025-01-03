/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:29:56 by abaurens          #+#    #+#             */
/*   Updated: 2025/01/03 01:48:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "bsq.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 ** @brief Load the given file, search for the bigest square and print it.
 **
 ** @param file The path to the map file
 */
static t_errorc  bsq(const char *file)
{
  t_errorc  error;
  t_bsq     bsq;
  int       fd;

  fd = open(file, O_RDONLY);
  if (file && fd < 0)
    return (F_OPN_ERR_C);
  error = get_bsq(fd, &bsq);
  if (!error)
    error = find_square(&bsq);
  if (!error)
  {
    place_square(&bsq);
    ft_putstr(bsq.map);
    free(bsq.map);
  }
  if (fd > 0 && close(fd) < 0)
    return (F_CLS_ERR_C);
  return (error);
}

int main(int ac, char **av)
{
  int i;

  i = 0;
  while (++i < ac)
  {
    ft_c_puterror(bsq(av[i]));
    if (i < (ac - 1))
      ft_putchar('\n');
  }
  return (0);
}
