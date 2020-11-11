/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:24:00 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/11 13:33:39 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort_sprit(void)
{
	t_sprit	*ptr;
	t_sprit	*tmp;

	ptr = g_sprits_ptr;
	while (ptr != NULL)
	{
		ptr->distance = ft_distance(ptr->x * TILE_SIZE, ptr->y * TILE_SIZE);
		ptr = ptr->next;
	}
	ptr = g_sprits_ptr;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		while (tmp != NULL)
		{
			if (tmp->distance > ptr->distance)
				ft_swap_sprit_conts(tmp, ptr);
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

