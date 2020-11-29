/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:26:07 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/29 23:22:20 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

/*
** Read the file and give the rgb color.
*/

int		get_color(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_check_line_space_last(str);
	while (str[i])
		if (str[i++] == ',')
			j++;
	if (j != 2)
		ft_file_error("The color line incorrect.\n");
	i = 1;
	while (str[i] == ' ')
		i++;
	j = i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			ft_file_error("The color line incorrect.\n");
		i++;
	}
	i = get_rgb(&str[j]);
	return (i);
}
