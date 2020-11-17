/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:08 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/17 20:33:29 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(void)
{
	size_t	i;
	char	*str;

	ft_check_first_last_line();
	i = 0;
	while (i < (size_t)g_data.map_height)
	{
		str = ft_strtrim(g_data.map_ptr[i], " ");
		if (str[0] == 0)
			ft_map_error("There is one or more empty lines in the map.\n");
		i++;
		ft_free(&str);
	}
	check_single_position();
}
