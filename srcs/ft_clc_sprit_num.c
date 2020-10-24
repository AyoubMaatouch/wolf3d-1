/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_sprit_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:24:10 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/24 20:51:22 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clc_sprit_num(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_data.map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(g_data.map_ptr[i]))
		{
			if (g_data.map_ptr[i][j] == '2')
				g_sprit_num++;
			j++;
		}
		i++;
	}
}
