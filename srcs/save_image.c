/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:45:02 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/16 20:47:21 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_image(void)
{
	t_images	img;
	t_rays		rays[g_data.win_width];

	mlx_clear_window(g_data.mlx_ptr, g_data.win_ptr);
	img.img = mlx_new_image(g_data.mlx_ptr, g_data.win_width,
			g_data.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	ft_update_player();
	cast_all_rays(rays);
	ft_draw_3d(&img, rays);
	ft_sort_sprit();
	ft_is_sprit_visible();
	draw_all_sprit(&img, rays);
	fill_file_bitmap(img);
	exit(0);
}
