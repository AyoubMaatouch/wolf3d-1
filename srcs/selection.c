/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:56:17 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/29 22:47:38 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

void	selection(char *line)
{
	if (g_data.map_ptr != NULL)
		ft_file_error("You have to put the map in the end.\n");
	else if (ft_memcmp(line, "R ", 2) == 0 && g_data.win_width == -1
			&& g_data.win_height == -1)
		get_resolution(line);
	else if (ft_memcmp(line, "F ", 2) == 0 && g_data.floor == -1)
		g_data.floor = get_color(line);
	else if (ft_memcmp(line, "C ", 2) == 0 && g_data.ceill == -1)
		g_data.ceill = get_color(line);
	else if (ft_memcmp(line, "NO ", 3) == 0 && g_txtr_n.file == NULL)
		g_txtr_n.file = get_texture(line);
	else if (ft_memcmp(line, "SO ", 3) == 0 && g_txtr_s.file == NULL)
		g_txtr_s.file = get_texture(line);
	else if (ft_memcmp(line, "WE ", 3) == 0 && g_txtr_w.file == NULL)
		g_txtr_w.file = get_texture(line);
	else if (ft_memcmp(line, "EA ", 3) == 0 && g_txtr_e.file == NULL)
		g_txtr_e.file = get_texture(line);
	else if (ft_memcmp(line, "S ", 2) == 0 && g_txtr_sprit.file == NULL)
		g_txtr_sprit.file = get_texture(line);
	else
		ft_file_error("You have to delete something in the data part.\n");
}
