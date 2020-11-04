/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/04 20:32:29 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_sp(int x, int y, int size, t_sprit *ptr, t_images *img, t_rays ray[])
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
			color = g_txtr_sprit.addr[j * size + i];
			if (color != 0)
				if (((x + i) >= 0 && (x + i) < g_data.win_width)
						&& ((y + j) >= 0 && (y + j) < g_data.win_height))
					my_mlx_pixel_put(img, x+i, y+j, color);
		}
	}
}

void	ft_is_sprit_visible(t_images *img, t_rays ray[])
{
	float	sprit_angle;
	float	dy;
	float	dx;
	t_sprit	*sprit_ptr;


	sprit_ptr = g_sprits_ptr;
	while (sprit_ptr != NULL)
	{
		dy = (sprit_ptr->y * TILE_SIZE + TILE_SIZE / 2) - g_player.y;
		dx = (sprit_ptr->x * TILE_SIZE + TILE_SIZE / 2) - g_player.x;
		sprit_ptr->distance = ft_distance(sprit_ptr->x * TILE_SIZE, sprit_ptr->y * TILE_SIZE);




		// normalize player view.
		while (g_player.direction < 0.0)
			g_player.direction += 360.0;
		while (g_player.direction > 360.0)
			g_player.direction -= 360.0;

		sprit_angle = atan2(dy, dx) * (180 / M_PI);

		// normalize sprite angle.
		while (sprit_angle - g_player.direction < -180.0)
			sprit_angle += 360.0;
		while (sprit_angle - g_player.direction > 180.0)
			sprit_angle -= 360.0;


		int size;
		if (g_data.win_height > g_data.win_width)
			size = (g_data.win_height / sprit_ptr->distance) * g_txtr_sprit.height;
		else
			size = (g_data.win_width / sprit_ptr->distance) * g_txtr_sprit.width;

		int y = g_data.win_height / 2 - size / 2;

		int x = (sprit_angle - g_player.direction) * g_data.win_width / 60 + ( g_data.win_width / 2 - size / 2);

		render_sp(x, y, size, sprit_ptr,img,ray);

		sprit_ptr = sprit_ptr->next;
	}

}
