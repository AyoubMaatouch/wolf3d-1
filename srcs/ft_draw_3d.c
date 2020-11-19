/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:04:06 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/19 14:08:12 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** arr[0] == x
** arr[1] == wall_height
** arr[2] == wall_top_pixel
** arr[3] == wall_bottom_pixel
*/

void	ft_draw_3d(t_images *img, t_rays ray[])
{
	float	dstnc;
	int		arr[4];

	arr[0] = -1;
	while (++arr[0] < g_data.win_width)
	{
		if ((dstnc = ray[arr[0]].distance * ft_cos(ray[arr[0]].ray_angle -
						g_player.direction)) == 0.0)
			dstnc = 1.0;
		arr[1] = (int)((TILE_SIZE / dstnc) * ((g_data.win_width / 2)
					/ ft_tan(FOV_ANGLE / 2)));
		arr[2] = (g_data.win_height / 2) - (arr[1] / 2);
		arr[2] = (arr[2] < 0) ? 0 : arr[2];
		arr[3] = (g_data.win_height / 2) + (arr[1] / 2);
		arr[3] = (arr[3] > g_data.win_height)
			? g_data.win_height : arr[3];
		draw_ciell_and_floor(img, arr[0], arr[2], arr[3]);
		draw_wall(img, ray, arr);
	}
}
