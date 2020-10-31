/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/31 14:12:30 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_is_sprit_visible()
{
	float	sprit_angle;
	float	dy;
	float	dx;
	t_sprit	*sprit_ptr;


	sprit_ptr = g_sprits_ptr;
	while (sprit_ptr != NULL)
	{
		// normalize player view.
		while (g_player.direction < 0.0)
			g_player.direction += 360.0;
		while (g_player.direction > 360.0)
			g_player.direction -= 360.0;

		dy = (sprit_ptr->y * TILE_SIZE) - g_player.y;
		dx = (sprit_ptr->x * TILE_SIZE) - g_player.x;
		sprit_angle = atan2(dy, dx) * (180 / M_PI);

		// normalize sprite angle.
		while (sprit_angle - g_player.direction < 0.0)
			sprit_angle += 360.0;
		while (sprit_angle - g_player.direction > 360.0)
			sprit_angle -= 360.0;

		printf("%f\n", sprit_angle);

		sprit_ptr = sprit_ptr->next;
	}

}
