/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 04:08:10 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 00:41:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			idx_of(const char *str, const char c)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

char		contains(const char *str, const char c)
{
	return (str[idx_of(str, c)] == c);
}

int			ft_strlen(const char *str)
{
	return (idx_of(str, '\0'));
}
