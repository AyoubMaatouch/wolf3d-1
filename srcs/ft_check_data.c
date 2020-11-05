/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:02:05 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/05 20:15:51 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_data(void)
{
	if (!g_data.map_ptr)
		ft_file_error("something wrong.\n");
	else if (g_data.win_width == -1 || g_data.win_height == -1
			|| g_data.floor == -1 || g_data.ceill == -1)
		ft_file_error("something wrong.\n");
	else if (g_data.map_height < 3 || g_data.map_width < 3)
		ft_map_error("The map is too small.\n");
	else if (g_data.player_view != 'N' && g_data.player_view != 'W'
			&& g_data.player_view != 'E' && g_data.player_view != 'S')
		ft_map_error("Where is the player.\n");
	else if (!g_txtr_e.file || !g_txtr_w.file || !g_txtr_s.file || !g_txtr_n.file || !g_txtr_sprit.file)
		ft_file_error("the texture files wrong.\n");
	else
		ft_check_map();
}
