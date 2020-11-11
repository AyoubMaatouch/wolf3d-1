/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_sprit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:17:30 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/11 13:19:58 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	draw_all_sprit(t_images *img, t_rays ray[])
{
	t_sprit	*sprit;

	sprit = g_sprits_ptr;
	while (sprit != NULL)
	{
		draw_sprite(sprit->screen_x, sprit->screen_y,sprit->size,sprit, img, ray);
		sprit = sprit->next;
	}
}
