/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:58:25 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/18 20:28:45 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_images *img, t_rays ray[], int top_pixel, int
		wall_bottom_pxl, int x)
{
	int				txtr_offset_x;
	int				txtr_offset_y;
	int				distance_from_top;
	unsigned int	color;
	int				y;

	(ray[x].was_hit_ver) ? (txtr_offset_x = (int)ray[x].wall_hity %
			TILE_SIZE) : (txtr_offset_x = (int)ray[x].wall_hitx %
				TILE_SIZE);
	y = top_pixel;
	while (y < wall_bottom_pxl)
	{
		distance_from_top = y + (wall_strip_height / 2) - (g_data.win_height / 2);
		if (!(ray[x].was_hit_ver) && ray[x].is_rayfacing_up)
		{
			txtr_offset_y = distance_from_top
				* ((float)g_txtr_n.width / wall_strip_height);
			color = g_txtr_n.addr[(txtr_offset_y
					* g_txtr_n.height) + txtr_offset_x];
		}
		else if (!(ray[x].was_hit_ver) && ray[x].is_rayfacing_down)
		{
			txtr_offset_y = distance_from_top
				* ((float)g_txtr_s.width / wall_strip_height);
			color = g_txtr_s.addr[(txtr_offset_y
					* g_txtr_s.height) + txtr_offset_x];
		}
		else if (ray[x].was_hit_ver && ray[x].is_rayfacing_left)
		{
			txtr_offset_y = distance_from_top
				* ((float)g_txtr_w.width / wall_strip_height);
			color = g_txtr_w.addr[(txtr_offset_y
					* g_txtr_w.height) + txtr_offset_x];
		}
		else
		{
			txtr_offset_y = distance_from_top
				* ((float)g_txtr_e.width / wall_strip_height);
			color = g_txtr_e.addr[(txtr_offset_y
					* g_txtr_e.height) + txtr_offset_x];
		}
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}
