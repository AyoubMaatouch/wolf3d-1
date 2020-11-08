/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/09 00:03:06 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
int		sprite_tranc(int x, int y, int sp_size)
{
	int point;

	point = (int)g_sptext.img_addr[g_sptext.w * (y * g_sptext.h / sp_size)
				+ (x * g_sptext.w / sp_size)];
	return (point);
}

*/
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
			color = g_txtr_sprit.addr[(j * g_txtr_sprit.height * g_txtr_sprit.height / size) + (i * g_txtr_sprit.width / size)];
				if (color != 0)
					if ((x + i >= 0 && x + i < g_data.win_width) && y + j >= 0 && y + j < g_data.win_height)
						my_mlx_pixel_put(img, x + i, y + j, color);
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

//		printf("%f %f\n", sprit->x, sprit->y);
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

		float sprite_size;
		//if (g_data.win_height > g_data.win_width)
			sprite_size = (g_data.win_height / sprit->distance) * g_txtr_sprit.height;
		//else
			//sprite_size = (g_data.win_width / sprit->distance) * g_txtr_sprit.width;

		float spritescreen_x = (sprit_angle - g_player.direction) * (g_data.win_width) / FOV_ANGLE + ((g_data.win_width) / 2 - sprite_size / 2);

		float spritescreen_y = g_data.win_height / 2 - sprite_size / 2;

		draw_sprite(spritescreen_x, spritescreen_y, sprite_size, sprit,img,ray);

		sprit = sprit->next;
	}
}
