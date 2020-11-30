/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first_last_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:26:51 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/30 20:41:33 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_first_last_line(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = (int)ft_strlen(g_data.map_ptr[i]);
	while (j < k)
	{
		if (!(g_data.map_ptr[i][j] == ' ' || g_data.map_ptr[i][j] == '1'))
			ft_map_error("The first line incorrect.\n");
		j++;
	}
	i = g_data.map_height - 1;
	j = 0;
	k = (int)ft_strlen(g_data.map_ptr[i]);
	while (j < k)
	{
		if (!(g_data.map_ptr[i][j] == ' ' || g_data.map_ptr[i][j] == '1'))
			ft_map_error("The last line incorrect.\n");
		j++;
	}
}
