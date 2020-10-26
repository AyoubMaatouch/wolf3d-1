/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:03:03 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/26 18:54:20 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

t_sprit		*ft_add_new_sprite(int y, int x)
{
	t_sprit	*new;

	new = malloc(sizeof(t_sprit));
	new->x = x + 1;
	new->y = y + 1;
	new->next = NULL;
	new->distance = 0.0;
	new->draw = -1;
	return (new);
}
