/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:38:43 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/23 20:53:04 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	cast_ray(t_rays *ray)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

	ft_ray_is_facing(ray);


	///////////////////// VER/////////////////
	//
	float	hor_wall_x;
	float	hor_wall_y;
	//int		found_hor_wall = FALSE;
	int		found_hor_wall;
	float	hor_hit_dis ;
	raycast_hor(ray, &hor_wall_x, &hor_wall_y, &found_hor_wall);





	float	ver_hit_dis;
	xintercept = (int)(g_player.x / TILE_SIZE) * TILE_SIZE;
	xintercept += ray->is_rayfacing_right ? TILE_SIZE : 0;

	yintercept = g_player.y + (xintercept - g_player.x) * ft_tan(ray->ray_angle);

	xstep = TILE_SIZE;
	xstep *= ray->is_rayfacing_right ? 1 : -1;

	ystep = TILE_SIZE * ft_tan(ray->ray_angle);
	ystep *= (ray->is_rayfacing_up && ystep > 0) ? -1 : 1;
	ystep *= (ray->is_rayfacing_down && ystep < 0) ? -1 : 1;

	float	nxt_ver_x = xintercept;
	float	nxt_ver_y = yintercept;

	float	ver_wall_x;
	float	ver_wall_y;
	int		found_ver_wall = FALSE;

	while (nxt_ver_x >= 0 && nxt_ver_x <= g_data.map_width * TILE_SIZE && nxt_ver_y >= 0
			&& nxt_ver_y <= g_data.map_height * TILE_SIZE)
	{
		float	x_check = nxt_ver_x + (ray->is_rayfacing_left ? -1 : 0);
		float	y_check = nxt_ver_y;

		if (has_wall_at(x_check, y_check) == 1)
		{
			ver_wall_x = nxt_ver_x;
			ver_wall_y = nxt_ver_y;
			found_ver_wall = TRUE;
			break ;
		}
		nxt_ver_x += xstep;
		nxt_ver_y += ystep;
	}
	hor_hit_dis = found_hor_wall ? ft_distance(hor_wall_x, hor_wall_y) : INT_MAX;
	ver_hit_dis = found_ver_wall ? ft_distance(ver_wall_x, ver_wall_y) : INT_MAX;

	if (ver_hit_dis < hor_hit_dis)
	{
		ray->wall_hitx = ver_wall_x;
		ray->wall_hity = ver_wall_y;
		ray->was_hit_ver = TRUE;
		ray->distance = ver_hit_dis;
	}
	else
	{
		ray->wall_hitx = hor_wall_x;
		ray->wall_hity = hor_wall_y;
		ray->was_hit_ver = FALSE;
		ray->distance = hor_hit_dis;
	}
}
