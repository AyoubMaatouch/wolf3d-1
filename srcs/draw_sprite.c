/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:21:08 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/21 14:59:19 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(int arr[], t_sprit *ptr, t_images *img, t_rays ray[])
{
	int color;
	int i;
	int j;

	i = -1;
	printf("%d\n", arr[2]);
	while (++i < arr[2])
	{
		if (arr[0] + i < 0 || arr[0] + i >= g_data.win_width)
			continue;
		printf("sprit = %f ; wall[%d] = %f\n", ptr->distance, arr[0] + i, ray[arr[0] +
				i].distance);
		if (ptr->distance >= ray[arr[0] + i].distance)
			continue;
		j = -1;
		while (++j < arr[2])
		{
			color = g_txtr_sprit.addr[g_txtr_sprit.height *
				(j * g_txtr_sprit.height / arr[2]) + (i * g_txtr_sprit.width /
						arr[2])];
			if (color != 0)
				if ((arr[0] + i >= 0 && arr[0] + i < g_data.win_width)
						&& arr[1] + j >= 0 && arr[1] + j < g_data.win_height)
					my_mlx_pixel_put(img, arr[0] + i, arr[1] + j, color);
		}
	}
	printf("############################################################################################\n");
}
