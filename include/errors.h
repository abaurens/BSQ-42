/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 05:06:07 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/23 22:49:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum
{
  NO_ERR_C,
  MAP_ERR_C,
  F_OPN_ERR_C,
  F_CLS_ERR_C,
  F_INV_ERR_C,
  MALLOC_ERR_C,
  UNKNOWN_ERR_C,
  ALREADY_MANAGED
} t_errorc;

typedef struct
{
  unsigned int  code;
  const char    *prefix;
  const char    *message;
  const char    *sufix;
} t_error;

void  ft_puterror(t_error e);
void  ft_c_puterror(t_errorc c);

#endif
