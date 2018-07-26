/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 04:07:34 by abaurens          #+#    #+#             */
/*   Updated: 2018/07/25 01:25:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

void				ft_replace(char *str, const char c, const char d)
{
	while (str && *str)
	{
		if (*str == c)
			*str = d;
		str++;
	}
}

char				*ft_strmcat(const char *s1, const char *s2, int l)
{
	int				i;
	int				j;
	int				len;
	char			*ret;

	ret = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (len > l && l > 0)
		len = l;
	if (len == 0 || (ret = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (s1 && s1[i] && i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2 && s2[++j] && i + j < len)
		ret[i + j] = s2[j];
	return (ret);
}

short				*compute_l(const char *s1, short l, const char *charset)
{
	int				i;
	unsigned char	j;
	int				len;
	short			*ret;

	ret = NULL;
	len = ft_strlen(s1);
	if (len > l && l > 0)
		len = l;
	if (len == 0 || (ret = malloc(sizeof(short) * (len + 1))) == NULL)
		return (NULL);
	ret[len] = -2;
	i = 0;
	while (s1 && s1[i] && i < len)
	{
		j = 0;
		while (charset && charset[j] && charset[j] != s1[i])
			j++;
		ret[i] = -(j - 1);
		i++;
	}
	return (ret);
}
