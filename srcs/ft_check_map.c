/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:08 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/31 14:51:10 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(void)
{
	int i;
	int j;
	int k;

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
	while (j < (int)ft_strlen(g_data.map_ptr[i]))
	{
		if (!(g_data.map_ptr[i][j] == ' ' || g_data.map_ptr[i][j] == '1'))
			ft_map_error();
		j++;
	}

	i = 1;
	while (i < g_data.map_height - 1)
	{
		j = 0;
		k = (int)ft_strlen(g_data.map_ptr[i]);
		while (j < k)
		{
			if (j == 0 && g_data.map_ptr[i][j] == ' ' && g_data.map_ptr[i][1] == '0')
				ft_map_error();
			else if (j == k - 1 && g_data.map_ptr[i][j] == ' ' && g_data.map_ptr[i][j - 2] == '0')
				ft_map_error();
			if ( j > 0 && j < k - 2 && g_data.map_ptr[i][j] == ' ')
			{
				ft_map_error();
			}
			j++;
		}
		i++;
	}
}
