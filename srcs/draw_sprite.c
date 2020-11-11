/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:21:08 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/11 13:21:15 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(int x, int y , int size, t_sprit *ptr, t_images *img, t_rays ray[])
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		if (x + i < 0 ||x + i >= g_data.win_width)
			continue;
		if (ptr->distance >= ray[x + i].distance)
			continue;
		j = -1;
		while (++j < size)
		{
			color = g_txtr_sprit.addr[g_txtr_sprit.height *
				(j * g_txtr_sprit.height / size) + (i * g_txtr_sprit.width / size)];
				if (color != 0)
					if ((x + i >= 0 && x + i < g_data.win_width)
							&& y + j >= 0 && y + j < g_data.win_height)
						my_mlx_pixel_put(img, x + i, y + j, color);
		}
	}
}
