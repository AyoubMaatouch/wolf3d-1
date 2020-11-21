/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/21 13:40:43 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_is_sprit_visible(void)
{
	float	sprit_angle;
	t_sprit	*s;

	s = g_sprits_ptr;
	while (s != NULL)
	{
		g_player.direction = normalize_angle(g_player.direction);
		sprit_angle = atan2(((s->y) * TILE_SIZE - (TILE_SIZE / 2)) - g_player.y,
				((s->x) * TILE_SIZE - (TILE_SIZE / 2)) - g_player.x)
			* 180 / M_PI;
		while (sprit_angle - g_player.direction > 180.0)
			sprit_angle -= 360.0;
		while (sprit_angle - g_player.direction < -180.0)
			sprit_angle += 360.0;
		if (g_data.win_height > g_data.win_width)
			s->size = (g_data.win_height / s->distance) * g_txtr_sprit.height;
		else
			s->size = (g_data.win_width / s->distance) * g_txtr_sprit.width;
		s->screen_x = ((sprit_angle - g_player.direction) * (g_data.win_width))
			/ FOV_ANGLE + ((g_data.win_width / 2) - (s->size / 2));
		s->screen_y = g_data.win_height / 2 - s->size / 2;
		s = s->next;
	}
}
