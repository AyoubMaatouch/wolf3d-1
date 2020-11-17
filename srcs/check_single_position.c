/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_single_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:23:37 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/17 20:43:16 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_single_position(void)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i++ < (size_t)g_data.map_height - 1)
	{
		j = -1;
		k = ft_strlen(g_data.map_ptr[i]);
		while (j++ < k)
		{
			if ((g_data.map_ptr[i][j] == 'W'
						|| g_data.map_ptr[i][j] == 'S'
						|| g_data.map_ptr[i][j] == 'E'
						|| g_data.map_ptr[i][j] == 'N'
						|| g_data.map_ptr[i][j] == '2'
						|| g_data.map_ptr[i][j] == '0')
					&& (ft_check_space(j + 1, g_data.map_ptr[i])
						|| ft_check_space(j - 1, g_data.map_ptr[i])
						|| ft_check_space(j, g_data.map_ptr[i + 1])
						|| ft_check_space(j, g_data.map_ptr[i - 1])))
				ft_map_error("You have a 0,2 or a player out side the map.\n");
		}
	}
}
