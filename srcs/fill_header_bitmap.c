/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_header_bitmap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:31:39 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/16 20:33:59 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_header_bitmap()
{
    int width = g_data.win_width;
    int height = g_data.win_height;
	unsigned int size;
	unsigned int first_pixel;
	char *header;
	unsigned int	headersize;
	unsigned short	plane;
	unsigned short	bits_per_pixel;
	size = (height * width) * 3 + 54;
	first_pixel = 54;
	header = malloc(54);
	headersize = 40;
	plane = 1;
	bits_per_pixel = 24;
	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(&header[2], &size, 4);
	ft_memcpy(&header[10], &first_pixel, 4);
	ft_memcpy(&header[14], &headersize, 4);
	ft_memcpy(&header[18], &width, 4);
	ft_memcpy(&header[22], &height, 4);
	ft_memcpy(&header[26], &plane, 2);
	ft_memcpy(&header[28], &bits_per_pixel, 2);
	return(header);
}
