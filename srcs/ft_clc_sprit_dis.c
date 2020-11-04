/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_sprit_dis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:58:13 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/04 18:54:04 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clc_sprit_dis(void)
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
		tmp = ptr;
		ptr = ptr->next;
		if (ptr != NULL)
			if (tmp->distance < ptr->distance)
				ft_swap_sprit_conts(tmp, ptr);
	}
}
