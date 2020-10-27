/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_sprit_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:24:10 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/27 14:49:43 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_sprit_pos(void)
{
	int		i;
	int		j;
	t_sprit	*head;

	head = NULL;
	i = 0;
	while (i < g_data.map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(g_data.map_ptr[i]))
		{
			if (g_data.map_ptr[i][j] == '2')
			{
				if (head == NULL && (g_sprits_ptr = head))
					head = ft_add_new_sprite(i, j);
				else
				{
					head->next = ft_add_new_sprite(i, j);
					head = head->next;
				}
			}
			j++;
		}
		i++;
	}
}
