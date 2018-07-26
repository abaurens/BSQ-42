/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 05:28:23 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 00:38:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			num_len(int nb)
{
	int		l;

	l = 1;
	if (nb < 0)
		l++;
	while (nb / 10 != 0 && ++l)
		nb /= 10;
	return (l);
}

int			ft_atoi(char *str)
{
	long	ret;
	char	sign;
	int		i;

	ret = 0;
	sign = 1;
	i = 0;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str && str[i] == '-')
		sign = -sign;
	if (str && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * sign);
}
