/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_sprit_dis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:58:13 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/26 19:10:31 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clc_sprit_dis(void)
{
	t_sprit	*ptr;

	ptr = g_sprits_ptr;
	while(ptr != NULL)
	{
		ptr->distance = ft_distance(ptr->x * TILE_SIZE, ptr->y * TILE_SIZE);
		ptr = ptr->next;
	}
}