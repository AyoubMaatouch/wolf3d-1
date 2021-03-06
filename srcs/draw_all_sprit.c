/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_sprit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:17:30 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/17 20:35:40 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_all_sprit(t_images *img, t_rays ray[])
{
	t_sprit	*sprit;
	int		arr[3];

	sprit = g_sprits_ptr;
	while (sprit != NULL)
	{
		arr[0] = sprit->screen_x;
		arr[1] = sprit->screen_y;
		arr[2] = sprit->size;
		draw_sprite(arr, sprit, img, ray);
		sprit = sprit->next;
	}
}
