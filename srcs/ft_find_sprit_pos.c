/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_sprit_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:24:10 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/04 18:55:23 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_sprit_pos(void)
{
	int		i;
	int		j;
	t_sprit	*tmp;

	i = 0;
	while (i < g_data.map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(g_data.map_ptr[i]))
		{
			if (g_data.map_ptr[i][j] == '2')
			{
				if (g_sprits_ptr == NULL)
					g_sprits_ptr = ft_add_new_sprite(i, j);
				else
				{
					tmp = ft_add_new_sprite(i, j);
					tmp->next = g_sprits_ptr;
					g_sprits_ptr = tmp;
				}
			}
			j++;
		}
		i++;
	}
}
