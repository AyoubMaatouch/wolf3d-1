/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:04:06 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/18 20:30:21 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_3d(t_images *img, t_rays ray[])
{
	float	dstnc;
	int		wall_bottom_pxl;
	int		wall_height;
	int		wall_top_pxl;
	int		x;

	x = -1;
	while (++x < g_data.win_width)
	{
		if ((dstnc = ray[x].distance * ft_cos(ray[x].ray_angle -
						g_player.direction)) == 0.0)
			dstnc = 1.0;
		wall_height = (int)((TILE_SIZE / dstnc) * ((g_data.win_width / 2)
					/ ft_tan(FOV_ANGLE / 2)));
		wall_top_pxl = (g_data.win_height / 2) - (wall_height / 2);
		wall_top_pxl = (wall_top_pxl < 0) ? 0 : wall_top_pxl;
		wall_bottom_pxl = (g_data.win_height / 2) + (wall_height / 2);
		wall_bottom_pxl = (wall_bottom_pxl > g_data.win_height)
			? g_data.win_height : wall_bottom_pxl;
		draw_ciell_and_floor(img, x, wall_top_pxl, wall_bottom_pxl);
		draw_wall(img, ray, wall_top_pxl, wall_bottom_pxl, x);
	}
}
