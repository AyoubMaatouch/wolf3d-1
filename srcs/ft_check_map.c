/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:08 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/03 18:54:47 by ynoam            ###   ########.fr       */
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
			ft_map_error("The first line incorrect.");
		j++;
	}
	i = g_data.map_height - 1;
	j = 0;
	k = (int)ft_strlen(g_data.map_ptr[i]);
	while (j < k)
	{
		if (!(g_data.map_ptr[i][j] == ' ' || g_data.map_ptr[i][j] == '1'))
			ft_map_error("The last line incorrect.");
		j++;
	}
}
void	ft_check_map(void)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	a;
	size_t	b;

	ft_check_first_last_line();
	i = 0;
	while (i < (size_t)g_data.map_height - 1)
		if (g_data.map_ptr[i++][0] == 0)
			ft_map_error("There is one or more empty lines in the map.");
	i = 1;
	j = 0;
	while (i < (size_t)g_data.map_height - 2)
	{
		k = ft_strlen(g_data.map_ptr[i]);
		a = ft_strlen(g_data.map_ptr[i + 1]);
		b = ft_strlen(g_data.map_ptr[i - 1]);
	//	while (j < k)
	//	{
	//		if (g_data.map_ptr[i][j] == '0' && ((j <= b && (g_data.map_ptr[i + 1][j] == 0 || g_data.map_ptr[i - 1][j] == 0 || g_data.map_ptr[i + 1][j] == ' ' || g_data.map_ptr[i - 1][j] == ' ')) || (g_data.map_ptr[i][j + 1] == ' ' || g_data.map_ptr[i][j - 1] == ' ' || g_data.map_ptr[i][j + 1] == 0)))
	//			ft_map_error("You have a 0,2 or a player out side the map.");
			j++;
		//}
		i++;
	}
}
