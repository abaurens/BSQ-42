/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 04:08:10 by abaurens          #+#    #+#             */
/*   Updated: 2025/01/03 01:43:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

u64 ft_atolu(char *str)
{
  u64   ret;
  int   i;

  i = 0;
  ret = 0;
  while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
    i++;
  while (str && str[i] >= '0' && str[i] <= '9')
  {
    ret = ret * 10 + (str[i] - '0');
    i++;
  }
  return (ret);
}

int idx_of(const char *const str, char c)
{
  int i;

  i = 0;
  while (str && str[i] && str[i] != c)
    i++;
  return (i);
}

void ft_bzero(void *const ptr, size_t size)
{
  u64 *p64 = ptr;
  u32 *p32;
  u16 *p16;
  u8 *p8;

  while (size >= sizeof(u64))
  {
    size -= sizeof(u64);
    *p64++ = 0;
  }
  p32 = (u32*)p64;
  if (size >= sizeof(u32))
  {
    size -= sizeof(u32);
    *p32++ = 0;
  }
  p16 = (u16*)p32;
  if (size >= sizeof(u16))
  {
    size -= sizeof(u16);
    *p16++ = 0;
  }
  p8 = (u8*)p16;
  if (size >= sizeof(u8))
    *p8 = 0;
}

char  contains(const char *const str, char c)
{
  return (str[idx_of(str, c)] == c);
}

int ft_strlen(const char *const str)
{
  return (idx_of(str, '\0'));
}
