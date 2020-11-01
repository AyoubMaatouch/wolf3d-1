/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/01 20:57:05 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_sp(int x, int y, int size, t_sprit *ptr)
{
	int col;
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		if (x + i < 0 || x + i >= g_resol.x)
			continue;
		if (ptr->dist >= g_raydist[x + i])
			continue;
		j = -1;
		while (++j < size)
		{
			col = g_txtr_w.addr[j * size + i];
			if (col != 0)
				if (((x + i) >= 0 && (x + i) < g_data.win_width) && ((y + j) >= 0 && (y + j) < g_data.win_height))
					mpp(&g_data, x + i, y + j, col);
		}
	}
}

void	ft_is_sprit_visible()
{
	float	sprit_angle;
	float	dy;
	float	dx;
//	float	distance;
	t_sprit	*sprit_ptr;


	sprit_ptr = g_sprits_ptr;
	while (sprit_ptr != NULL)
	{
		dy = (sprit_ptr->y * TILE_SIZE) - g_player.y;
		dx = (sprit_ptr->x * TILE_SIZE) - g_player.x;
		sprit_ptr->distance = ft_distance(sprit_ptr->x, sprit_ptr->y);




		// normalize player view.
		while (g_player.direction < 0.0)
			g_player.direction += 360.0;
		while (g_player.direction > 360.0)
			g_player.direction -= 360.0;

		sprit_angle = atan2(dy, dx) * (180 / M_PI) - g_player.direction;

		// normalize sprite angle.
		while (sprit_angle - g_player.direction < -180.0)
			sprit_angle += 360.0;
		while (sprit_angle - g_player.direction > 180.0)
			sprit_angle -= 360.0;


		int size;
		if (g_data.win_height > g_data.win_width)
			size = (g_data.win_height / sprit_ptr->distance) * TILE_SIZE;
		else
			size = (g_data.win_width / sprit_ptr->distance) * TILE_SIZE;

		int y = g_data.win_height / 2 - size / 2;

		int x = (sprit_angle - g_player.direction) * g_data.win_width / (60 * M_PI / 180) + ( g_data.win_width / 2 - size / 2);

		render_sp(x, y, size, sprit_ptr);

		sprit_ptr = sprit_ptr->next;
	}

}
