/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 07:27:34 by bmulamba          #+#    #+#             */
/*   Updated: 2018/08/20 07:29:43 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key(int keycode, t_env *env)
{
	env = NULL;
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (0);
}

int		expose(t_img *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

void	hook(t_img *img, t_env **env)
{
	mlx_key_hook(img->win, key, env);
	mlx_expose_hook(img->win, expose, img);
	mlx_loop(img->mlx);
}
