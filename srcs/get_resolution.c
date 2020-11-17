/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:15:45 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/17 20:54:19 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

/*
** Read the first line and give the resolution of the window.
*/

void	get_resolution(char *strim)
{
	char	**parts;
	int		i;

	i = 0;
	parts = ft_split(strim, ' ');
	while (parts[i++] != NULL)
		;
	if (i != 4)
		ft_file_error("Something wrong in th resolution line\n");
	i = 0;
	while (parts[1][i])
		if (ft_isdigit(parts[1][i++]) == 0)
			ft_file_error("Something wrong in th resolution line\n");
	i = 0;
	while (parts[2][i])
		if (ft_isdigit(parts[2][i++]) == 0)
			ft_file_error("Something wrong in th resolution line\n");
	g_data.win_width = ft_atoi(parts[1]);
	g_data.win_height = ft_atoi(parts[2]);
	if (g_data.win_width < 1 || g_data.win_height < 1)
		ft_file_error("the resolution data too small\n");
	else if (g_data.win_width > 2560 || g_data.win_height > 1440)
		ft_file_error("the resolution data too small\n");
	ft_free_double_ptr(&parts);
}
