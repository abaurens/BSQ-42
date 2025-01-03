/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:51:25 by abaurens          #+#    #+#             */
/*   Updated: 2025/01/03 01:53:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUFF_SIZE 14

typedef struct stat filestat;

/**
 ** @brief Validate the charset values.
 ** The charset must not contain any duplicate characters
 **
 ** @param charset 
 */
static bool validate_charset(const char *charset)
{
  int i = 0;

  while (*charset)
  {
    i = 0;
    while (charset[++i])
      if (charset[i] == *charset)
        return false;
    ++charset;
  }
  return true;
}

/**
 ** @brief Load the header data
 **
 ** @param fd The input file descriptor
 ** @param bsq The BSQ instance in which to load the header
 ** @param buff An input buffer in which the bytes are loaded
 */
static int preload_file(int fd, t_bsq *const bsq, char *buff, int *res)
{
  int i;
  int rd;
  u64 height;

  rd = read(fd, buff, BUFF_SIZE);
  if (rd < 0)
    return (F_OPN_ERR_C);
  i = 0;
  while (buff[i] >= '0' && buff[i] <= '9')
    ++i;
  if (i == 0 || i > 10 || (i + CHARSET_SIZE) >= rd)
    return (MAP_ERR_C);
  height = ft_atolu(buff);
  if (height > INT_MAX)
    return (MAP_ERR_C);
  bsq->h = (int)height;
  memcpy(bsq->charset, buff + i, CHARSET_SIZE);
  bsq->charset[CHARSET_SIZE] = 0;
  if (buff[i + CHARSET_SIZE] != '\n' || !validate_charset(bsq->charset))
    return (MAP_ERR_C);
  *res = i + CHARSET_SIZE + 1;
  return NO_ERR_C;
}

/**
 ** @brief Load the BSQ file from an already open file descriptor
 ** 
 ** @param fd The input file descriptor
 ** @param bsq The BSQ instance in which to load the file
 */
t_errorc  get_bsq(int fd, t_bsq *const bsq)
{
  int rd;
  size_t size;
  filestat st;
  char buff[BUFF_SIZE];

  ft_bzero(bsq, sizeof(t_bsq));
  if (fstat(fd, &st) < 0)
    return (F_OPN_ERR_C);
  size = preload_file(fd, bsq, buff, &rd);
  if (size != NO_ERR_C)
    return (size);
  size = st.st_size - rd;
  bsq->map = malloc((sizeof(char) + sizeof(short)) * size);
  if (!bsq->map)
    return (UNKNOWN_ERR_C);
  size = (BUFF_SIZE - rd);
  if (size > 0)
    memcpy(bsq->map, buff + rd, size);
  while ((rd = read(fd, bsq->map + size, READ_SIZE)) > 0)
    size += rd;
  bsq->map[size] = 0;
  bsq->w = 0;
  bsq->matrix = (short *)(bsq->map + size + 1);
  return (NO_ERR_C);
}
