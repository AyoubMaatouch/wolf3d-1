/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/08 20:54:34 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(int x, int y, int size, t_sprit *ptr, t_images *img, t_rays ray[])
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		if (x + i < 0 || x + i >= g_data.win_width)
			continue;
		if (ptr->distance >= ray[x + i].distance)
			continue;
		j = -1;
		while (++j < size)
		{
			if (((x + i) >= 0 && (x + i) < g_data.win_width) && ((y + j) >= 0 && (y + j) < g_data.win_height))
			{
				if (j < 64 && i < 64)
				{
					color = g_txtr_sprit.addr[(j * g_txtr_sprit.height) + i];
					if (color != 0)
						my_mlx_pixel_put(img, x + i, y + j, color);
				}
			}
		}
	}
}

void	ft_is_sprit_visible(t_images *img, t_rays ray[])
{
	float	sprit_angle;
	float	dy;
	float	dx;
	t_sprit	*sprit;


	sprit = g_sprits_ptr;
	while (sprit != NULL)
	{
		dy = ((sprit->y) * TILE_SIZE - TILE_SIZE/2) - g_player.y;
		dx = ((sprit->x) * TILE_SIZE - TILE_SIZE/2) - g_player.x;
		sprit->distance = ft_distance(sprit->x * TILE_SIZE - TILE_SIZE/2, sprit->y * TILE_SIZE - TILE_SIZE/2);




		// normalize player view.
		while (g_player.direction < 0.0)
			g_player.direction += 360.0;
		while (g_player.direction > 360.0)
			g_player.direction -= 360.0;

		sprit_angle = atan2(dy, dx) * 180 / M_PI;

		// normalize sprite angle.
		while (sprit_angle - g_player.direction > 180.0)
			sprit_angle -= 360.0;
		while (sprit_angle - g_player.direction < -180.0)
			sprit_angle += 360.0;

		float spritescal;
		if (g_data.win_height > g_data.win_width)
			spritescal = (g_data.win_height / sprit->distance) * g_txtr_sprit.height;
		else
			spritescal = (g_data.win_width / sprit->distance) * g_txtr_sprit.width;

		float spritescreenx = (sprit_angle - g_player.direction) * (g_data.win_width) / 60 + ( (g_data.win_width) / 2 - spritescal / 2);

		float spritescreeny = g_data.win_height / 2 - spritescal / 2;

		draw_sprite(spritescreenx, spritescreeny, spritescal, sprit,img,ray);

		sprit = sprit->next;
	}

}
