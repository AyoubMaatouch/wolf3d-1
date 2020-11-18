/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ciell_and_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:26:48 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/18 18:39:33 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ciell_and_floor(t_images *img, int x,
		int wall_top_pxl, int wall_bottom_pxl)
{
	int y;

	y = 0;
	while (y < wall_top_pxl && wall_top_pxl < g_data.win_width)
		my_mlx_pixel_put(img, x, y++, g_data.ceill);
	y = wall_bottom_pxl;
	while (y < g_data.win_height)
		my_mlx_pixel_put(img, x, y++, g_data.floor);
}
