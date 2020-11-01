/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/01 19:04:24 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

		printf("%f\n", sprit_angle);
		printf("------------------------\n");
		int size;
		if (g_data.win_height > g_data.win_width)
			size = (g_data.win_height / ft_distance(dx, dy)) * TILE_SIZE;
		else
			size = (g_data.win_width / ft_distance(dx, dy)) * TILE_SIZE;

		int y = g_data.win_height / 2 - size / 2;

		int x = (sprit_angle - g_player.direction) * g_data.win_width / (60 * M_PI / 180) + ( g_data.win_width / 2 - size / 2);

		sprit_ptr = sprit_ptr->next;
	}

}
