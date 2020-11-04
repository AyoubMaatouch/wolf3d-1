/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:08 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/04 18:49:15 by ynoam            ###   ########.fr       */
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

int		ft_check_space(size_t j, char *str)
{
	size_t	k;

	k = ft_strlen(str);
	if (j < 0 || k < j || str[j] == ' ' || str[j] == 0)
		return (1);
	return (0);
}

void	ft_check_map(void)
{
	size_t	i;
	size_t	j;
	size_t	k;
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
	i = 1;
	while (i < (size_t)g_data.map_height - 2)
	{
		j = 0;
		k = ft_strlen(g_data.map_ptr[i]);
		while (j < k)
		{
			if (g_data.map_ptr[i][j] == '0' && (ft_check_space(j+1, g_data.map_ptr[i]) || ft_check_space(j-1, g_data.map_ptr[i]) || ft_check_space(j, g_data.map_ptr[i+1]) || ft_check_space(j, g_data.map_ptr[i-1])))
				ft_map_error("You have a 0,2 or a player out side the map.\n");
			else  if ((g_data.map_ptr[i][j] == 'W' || g_data.map_ptr[i][j] == 'S' || g_data.map_ptr[i][j] == 'E' || g_data.map_ptr[i][j] == 'N' || g_data.map_ptr[i][j] == '2') && (ft_check_space(j+1, g_data.map_ptr[i]) || ft_check_space(j-1, g_data.map_ptr[i]) || ft_check_space(j, g_data.map_ptr[i+1]) || ft_check_space(j, g_data.map_ptr[i-1])))
				ft_map_error("You have a 0,2 or a player out side the map.\n");
			j++;
		}
		i++;
	}
}
