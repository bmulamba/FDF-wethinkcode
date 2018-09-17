/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 07:29:44 by bmulamba          #+#    #+#             */
/*   Updated: 2018/07/21 10:15:46 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		nbr;

	nbr = 0;
	while (*str <= 32)
		str++;
	sign = (*str == '-' && str++) ? -1 : 1;
	while (*str && *str >= 48 && *str <= 57)
		nbr = (nbr * 10) + (*str++ - 48);
	return (nbr * sign);
}
