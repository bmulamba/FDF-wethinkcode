/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 07:30:30 by bmulamba          #+#    #+#             */
/*   Updated: 2018/07/21 10:15:56 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_wlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != ' ' && s[len] != '\n')
		len++;
	return (len);
}

int		countwords(char *str)
{
	int	count;
	int	nb;

	count = 0;
	nb = 0;
	while (str[nb] != '\0' && str[nb] != '\n')
	{
		if (str[nb] == ' ' && str[nb + 1] != '\0')
			count++;
		nb++;
	}
	return (count);
}

char	**ft_strsplit(char *str)
{
	char	**r;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(r = (char**)malloc(((countwords(str) + 2)) * sizeof(char*))))
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\n') && j++)
			while (str[i] == ' ')
				i++;
		if (!(r[j] = (char*)malloc(((ft_wlen(str + i) + 1)) * sizeof(char))))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\n' && str[i])
			r[j][k++] = str[i++];
		r[j][k] = '\0';
	}
	r[j + 1] = 0;
	return (r);
}
