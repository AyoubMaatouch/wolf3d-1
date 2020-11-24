/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:02:12 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/24 20:56:59 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_ver(t_rays *ray, float *ver_wall_x,
		float *ver_wall_y, int *found_ver_wall)
{
	float	nxt_ver_x;
	float	nxt_ver_y;
	float	xstep;
	float	ystep;
	float	x_check;

	nxt_ver_x = (int)(g_player.x / TILE_SIZE) * TILE_SIZE;
	nxt_ver_x += ray->is_rayfacing_right ? TILE_SIZE : 0;
	nxt_ver_y = g_player.y + (nxt_ver_x - g_player.x) * ft_tan(ray->ray_angle);
	xstep = TILE_SIZE * (ray->is_rayfacing_right ? 1 : -1);
	ystep = TILE_SIZE * ft_tan(ray->ray_angle);
	ystep *= (ray->is_rayfacing_up && ystep > 0) ? -1 : 1;
	ystep *= (ray->is_rayfacing_down && ystep < 0) ? -1 : 1;
	*found_ver_wall = FALSE;
	while (nxt_ver_x >= 0 && nxt_ver_x <= g_data.map_width * TILE_SIZE
			&& nxt_ver_y >= 0 && nxt_ver_y <= g_data.map_height * TILE_SIZE)
	{
		x_check = nxt_ver_x + (ray->is_rayfacing_left ? -1 : 0);
		if (has_wall_at(x_check, nxt_ver_y) == 1 && (*found_ver_wall = TRUE)
				&& (*ver_wall_x = nxt_ver_x)
				&& (*ver_wall_y = nxt_ver_y))
			break ;
		nxt_ver_x += xstep;
		nxt_ver_y += ystep;
	}
}
