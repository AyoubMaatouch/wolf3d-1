/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:08 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/31 18:10:22 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(void)
{
	/*
	int i;
	int j;
	int k;
	int g;

	/// first line of the map
	i = 0;
	j = 0;
	while (j < (int)ft_strlen(g_data.map_ptr[i]))
	{
		if (!(g_data.map_ptr[i][j] == ' ' || g_data.map_ptr[i][j] == '1'))
			ft_map_error();
		j++;
	}
	i = g_data.map_height - 1;
	j = 0;
	/// end line of the map
	while (j < (int)ft_strlen(g_data.map_ptr[i]))
	{
		if (!(g_data.map_ptr[i][j] == ' ' || g_data.map_ptr[i][j] == '1'))
			ft_map_error();
		j++;
	}

	i = 0;
	while (i < g_data.map_height - 1)
	{
		j = 0;
		g = (int)ft_strlen(g_data.map_ptr[i]) - 1;
		k = (int)ft_strlen(g_data.map_ptr[i + 1]) - 1;
		while (j < g)
		{
			if (g_data.map_ptr[i][j] == ' ' && j <= k && g_data.map_ptr[i+1][j] == '0')
				ft_map_error();
			else if (g_data.map_ptr[i][j] == ' ' && i > 0 && j <= k && g_data.map_ptr[i-1][j] == '0')
				ft_map_error();
			else if(g_data.map_ptr[i][j] == '0' && i > 0 && j <= k && g_data.map_ptr[i-1][j] == '0')
				ft_map_error();
			j++;
		}
		i++;
	}
	*/
}
