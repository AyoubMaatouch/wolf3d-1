/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/09 20:54:03 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// change x && y && size to sprit->...
void	draw_sprite(t_sprit *ptr, t_images *img, t_rays ray[])
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		if (sprit->screen_x + i < 0 || sprit->screen_x + i >= g_data.win_width)
			continue;
		if (ptr->distance >= ray[sprit->screen_x + i].distance)
			continue;
		j = -1;
		while (++j < sprit-sprite_size)
		{
			color = g_txtr_sprit.addr[g_txtr_sprit.height *
				(j * g_txtr_sprit.height / size) + (i * g_txtr_sprit.width / size)];
				if (color != 0)
					if ((x + i >= 0 && x + i < g_data.win_width)
							&& y + j >= 0 && y + j < g_data.win_height)
						my_mlx_pixel_put(img, x + i, y + j, color);
		}
	}
}

void	draw_all_sprit(void)
{
	t_sprit	*sprit;

	sprit = g_sprits_ptr;
	while (sprit != NULL)
	{
		draw_sprite(sprit, t_images *img, t_rays ray[])
		sprt = sprt->next;
	}
}
void	ft_is_sprit_visible(t_images *img, t_rays ray[])
{
	float	sprit_angle;
	t_sprit	*sprt;


	sprt = g_sprits_ptr;
	while (sprt != NULL)
	{
		sprt->distance = ft_distance(sprt->x * TILE_SIZE - TILE_SIZE / 2, sprt->y * TILE_SIZE - TILE_SIZE / 2);
		while (g_player.direction < 0.0)
			g_player.direction += 360.0;
		while (g_player.direction > 360.0)
			g_player.direction -= 360.0;
		sprit_angle = atan2(((sprt->y) * TILE_SIZE - TILE_SIZE/2) - g_player.y,
				((sprt->x) * TILE_SIZE - TILE_SIZE/2) - g_player.x) * 180 / M_PI;
		while (sprit_angle - g_player.direction > 180.0)
			sprit_angle -= 360.0;
		while (sprit_angle - g_player.direction < -180.0)
			sprit_angle += 360.0;
			sprt->sprite_size = (g_data.win_height / sprt->distance) * g_txtr_sprit.height;
		sprt->screen_x = (sprit_angle - g_player.direction) * (g_data.win_width)
			/ FOV_ANGLE + ((g_data.win_width) / 2 - sprite_size / 2);
		sprt->screen_y = g_data.win_height / 2 - sprite_size / 2;
		//draw_sprite(sprite_size, sprt,img,ray);
		sprt = sprt->next;
	}
}
