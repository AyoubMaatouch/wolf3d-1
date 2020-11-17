/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_header_bitmap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:31:39 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/17 14:53:20 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_header_bitmap(void)
{
	char			*header;
	unsigned int	size;
	unsigned int	first_pixel;
	unsigned int	headersize;
	unsigned short	var2[2];

	header = malloc(54);
	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	size = (g_data.win_height * g_data.win_width) * 3 + 54;
	ft_memcpy(&header[2], &size, 4);
	first_pixel = 54;
	ft_memcpy(&header[10], &first_pixel, 4);
	headersize = 40;
	ft_memcpy(&header[14], &headersize, 4);
	ft_memcpy(&header[18], &g_data.win_width, 4);
	ft_memcpy(&header[22], &g_data.win_height, 4);
	var2[0] = 1;
	ft_memcpy(&header[26], &var2, 2);
	var2[1] = 24;
	ft_memcpy(&header[28], &var2[1], 2);
	return (header);
}
