/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:25:58 by bmulamba          #+#    #+#             */
/*   Updated: 2018/07/21 14:49:36 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pixel_put_to_img(t_img *img, char *image, int x, int y)
{
	if (img->bpp == 0 || img->len == 0)
		exit(0);
	image[(x + y)] = 0xFF;
	image[(x + y) + 1] = 0xFF;
	image[(x + y) + 2] = 0xFF;
	return (0);
}

void	iso_proj(t_env **env, t_img *img)
{
	t_env		*elem;
	float		cst;

	(void)img;
	elem = *env;
	cst = 1.4;
	while (elem != NULL)
	{
		elem->env_x = ((cst * (elem->x * 10)) -
				(cst * (elem->y * 10)) + (WIN_H / 10));
		elem->env_y = ((elem->z * (-5)) + (cst / 6) * (elem->x * (50)) +
				(cst / 6) * (elem->y * 10) + (WIN_W / 10));
		elem = elem->next;
	}
}

void	display(t_env **env, t_img *img, char *image)
{
	t_env	*p1;
	t_env	*p2;

	p1 = *env;
	while (p1 != NULL)
	{
		p2 = *env;
		while (p2 != NULL)
		{
			if (p1->x == p2->x - 1 && p1->y == p2->y)
				draw(img, image, p1, p2);
			if (p1->y == p2->y - 1 && p1->x == p2->x)
				draw(img, image, p1, p2);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}
