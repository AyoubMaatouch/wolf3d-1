/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sprit_conts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:35:54 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/27 17:42:48 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap_sprit_conts(t_sprit *one, t_sprit *two)
{
	float	x;
	float	y;
	float	distance;

	x = one->x;
	y = one->y;
	distance = one->distance;
	one->x = two->x;
	one->y = two->y;
	one->distance = two->distance;
	two->y = y;
	two->x = x;
	two->distance = distance;
}
