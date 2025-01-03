/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 05:06:43 by abaurens          #+#    #+#             */
/*   Updated: 2025/01/03 01:43:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "errors.h"
#include "bsq.h"

const t_error g_errors[] =
{
  {0, NULL, NULL, NULL},
  {1, NULL, "map error", "\n"},
  {2, "bsq: \033[31;01merror:\033[00m ", "can't open file", "\n"},
  {3, "bsq: \033[31;01merror:\033[00m ", "can't close file", "\n"},
  {4, "bsq: \033[31;01merror:\033[00m ", "invalid file", "\n"},
  {5, "bsq: \033[31;01merror:\033[00m ", "malloc error", "\n"},
  {UNKNOWN_ERR_C, "bsq: \033[31;01merror:\033[00m ", "unknown error", "\n"}
};

void  ft_puterror(t_error e)
{
  if (e.prefix)
    write(2, e.prefix, ft_strlen(e.prefix));
  if (e.message)
    write(2, e.message, ft_strlen(e.message));
  if (e.sufix)
    write(2, e.sufix, ft_strlen(e.sufix));
}

void  ft_c_puterror(t_errorc c)
{
  if (c != ALREADY_MANAGED)
    ft_puterror(g_errors[c]);
}
