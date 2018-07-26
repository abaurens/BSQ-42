/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:29:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 03:46:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "bsq.h"

int			main(int ac, char **av)
{
	int		i;

	i = 1;
	ft_c_puterror(bsq(av[i]));
	while (++i < ac)
	{
		ft_putchar('\n');
		ft_c_puterror(bsq(av[i]));
	}
	return (0);
}
