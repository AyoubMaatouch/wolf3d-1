/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sprit_visible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:36 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/30 20:48:18 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_is_sprit_visible()
{
	float	sprit_angle;
	t_sprit	*ptr;


	ptr = g_sprits_ptr;
	while (ptr != NULL)
	{
		sprit_angle = atan2(ptr->y * TILE_SIZE - g_player.y, ptr->x * TILE_SIZE - g_player.x);
		printf("----------------------------------------\n");
		printf("x = %f ; y = %f ; %f\n",ptr->x, ptr->y, sprit_angle - g_player.direction);
		ptr = ptr->next;
	}

}
