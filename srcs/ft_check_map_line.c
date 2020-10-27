/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:44:24 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/27 14:52:22 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int	ft_check_map_line(char *str, int position)
{
	int			i;
	static int	player;

	i = 0;
	while (str[i])
		if ((str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
				&& player == 0)
		{
			player = 1;
			g_player.x = i * TILE_SIZE + (TILE_SIZE / 2);
			g_player.y = (position + 1) * TILE_SIZE + (TILE_SIZE / 2);
			g_data.player_view = str[i];
			i++;
		}
		else if (str[i] == '0' || str[i] == '1' || str[i] == '2'
				|| str[i] == ' ')
			i++;
		else
			ft_map_error();
	return (i);
}
