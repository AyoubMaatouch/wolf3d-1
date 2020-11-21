/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:44:24 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/21 17:49:03 by ynoam            ###   ########.fr       */
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
			g_player.x = i * TILE_SIZE + HALF_TILE_SIZE;
			g_player.y = (position + 1) * TILE_SIZE + HALF_TILE_SIZE;
			g_data.player_view = str[i];
			i++;
		}
		else if (str[i] == '0' || str[i] == '1' || str[i] == '2'
				|| str[i] == ' ')
			i++;
		else if (player == 1)
			ft_map_error("Duplicate player.\n");
		else
			ft_map_error("You have a non allowed caracter in the map.\n");
	return (i);
}
