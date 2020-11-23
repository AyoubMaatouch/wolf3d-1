/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:22:03 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/23 20:51:16 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_hor(t_rays *ray, float *hor_wall_x, float *hor_wall_y, int *found_hor_wall)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	y_check;
	float	nxt_hor_x;
	float	nxt_hor_y;

	yintercept = (int)(g_player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += ray->is_rayfacing_down ? TILE_SIZE : 0;
	xintercept = g_player.x + (yintercept - g_player.y) / ft_tan(ray->ray_angle);
	ystep = TILE_SIZE;
	ystep *= ray->is_rayfacing_up ? -1 : 1;
	xstep = TILE_SIZE / ft_tan(ray->ray_angle);
	xstep *= (ray->is_rayfacing_left && xstep > 0) ? -1 : 1;
	xstep *= (ray->is_rayfacing_right && xstep < 0) ? -1 : 1;
	nxt_hor_x = xintercept;
	nxt_hor_y = yintercept;
	*found_hor_wall = FALSE;
	while (nxt_hor_x >= 0 && nxt_hor_x <= g_data.map_width * TILE_SIZE
			&& nxt_hor_y >= 0 && nxt_hor_y <= g_data.map_height * TILE_SIZE)
	{
		y_check = nxt_hor_y + (ray->is_rayfacing_up ? -1 : 0);
		if (has_wall_at(nxt_hor_x, y_check) == 1)
		{
			*hor_wall_x = nxt_hor_x;
			*hor_wall_y = nxt_hor_y;
			*found_hor_wall = TRUE;
			break ;
		}
		nxt_hor_x += xstep;
		nxt_hor_y += ystep;
	}
}
