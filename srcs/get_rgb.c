/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:56:28 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/05 20:51:35 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int	get_rgb(char *str)
{
	char	**rgb;
	char	**rgb2;
	int		i;
	int		j;

	rgb = ft_split(str, ',');
	rgb2 = ft_split(rgb[0], ' ');
	if (!rgb2[1])
		ft_file_error("rgb value illegal.\n");
	j = ft_atoi(rgb2[1]);
	if (j < 0 || j > 255)
		ft_file_error("rgb value illegal.\n");
	i = j << 16;
	j = ft_atoi(rgb[1]);
	if (j < 0 || j > 255)
		ft_file_error("rgb value illegal.\n");
	i |= j << 8;
	j = ft_atoi(rgb[2]);
	if (j < 0 || j > 255)
		ft_file_error("rgb value illegal.\n");
	ft_free_double_ptr(&rgb2);
	free(rgb2);
	ft_free_double_ptr(&rgb);
	free(rgb);
	return (i |= j);
}
