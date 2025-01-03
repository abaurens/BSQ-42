/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 22:53:23 by abaurens          #+#    #+#             */
/*   Updated: 2025/01/03 00:27:21 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

void  ft_putstr(char *str)
{
  write(1, str, ft_strlen(str));
}

void  ft_putnbr(int nb, int l)
{
  long  n;

  n = nb;
  if (nb < 0)
  {
    l--;
    n = -n;
    ft_putchar('-');
  }
  if (nb / 10 == 0)
    while (l > 1)
    {
      ft_putchar(' ');
      l--;
    }
  if (nb / 10 > 0 || l > 1)
    ft_putnbr(nb / 10, l - 1);
  ft_putchar(nb % 10 + '0');
}
