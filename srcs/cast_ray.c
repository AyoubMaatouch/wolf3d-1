/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:38:43 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/24 20:56:02 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_rays *ray)
{
	float	hor_dis;
	float	ver_dis;
	float	hor_arr[2];
	float	ver_arr[2];
	int		found_arr[2];

	ft_ray_is_facing(ray);
	raycast_hor(ray, &hor_arr[0], &hor_arr[1], &found_arr[0]);
	raycast_ver(ray, &ver_arr[0], &ver_arr[1], &found_arr[1]);
	hor_dis = found_arr[0] ? ft_distance(hor_arr[0], hor_arr[1]) : INT_MAX;
	ver_dis = found_arr[1] ? ft_distance(ver_arr[0], ver_arr[1]) : INT_MAX;
	if (ver_dis < hor_dis)
	{
		ray->wall_hitx = ver_arr[0];
		ray->wall_hity = ver_arr[1];
		ray->was_hit_ver = TRUE;
		ray->distance = ver_dis;
	}
	else
	{
		ray->wall_hitx = hor_arr[0];
		ray->wall_hity = hor_arr[1];
		ray->was_hit_ver = FALSE;
		ray->distance = hor_dis;
	}
}
