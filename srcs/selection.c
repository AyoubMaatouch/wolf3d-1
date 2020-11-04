/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:56:17 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/04 16:37:00 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

void	selection(char *line)
{
	if (g_data.map_ptr != NULL)
		ft_file_error("You have to put the map in the end.\n");
	else if (line[0] == 'R' && g_data.win_width == -1)
		get_resolution(line);
	else if (line[0] == 'N' && line[1] == 'O' && g_txtr_n.file == NULL)
		g_txtr_n.file = get_texture(line);
	else if (line[0] == 'S' && line[1] == 'O' && g_txtr_s.file == NULL)
		g_txtr_s.file = get_texture(line);
	else if (line[0] == 'W' && line[1] == 'E' && g_txtr_w.file == NULL)
		g_txtr_w.file = get_texture(line);
	else if (line[0] == 'E' && line[1] == 'A' && g_txtr_e.file == NULL)
		g_txtr_e.file = get_texture(line);
	else if (line[0] == 'S' && g_txtr_sprit.file == NULL)
		g_txtr_sprit.file = get_texture(line);
	else if (line[0] == 'F' && g_data.floor == -1)
		g_data.floor = get_color(line);
	else if (line[0] == 'C' && g_data.ceill == -1)
		g_data.ceill = get_color(line);
	else
		ft_file_error("You have to delete something in the data part.\n");
}
