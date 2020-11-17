/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_bitmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:36:32 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/17 14:44:59 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_file_bitmap(t_images img)
{
	int		fd;
	int		x;
	int		y;
	char	*image_name;
	char	*ptr;

	image_name = ft_strdup("screenshot.bmp");
	if ((fd = open(image_name, O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IXUSR)) < 0)
		ft_sys_error(image_name);
	ptr = fill_header_bitmap();
	write(fd, ptr, 54);
	ft_free(&ptr);
	ft_free(&image_name);
	y = g_data.win_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < g_data.win_width)
		{
			write(fd, &((int*)img.addr)[x + y * (img.line_length / 4)], 3);
			x++;
		}
		y--;
	}
}
