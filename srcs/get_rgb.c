/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:56:28 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/29 23:54:52 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int	shift_left(int num, int shift)
{
	return (num << shift);
}

int	get_rgb(char *str)
{
	char	**rgb;
	int		i;
	int		j;

	rgb = ft_split(str, ',');
	if (rgb[0] == NULL || !ft_isdigit(rgb[0][0]))
		ft_file_error("rgb value illegal.\n");
	j = ft_atoi(rgb[0]);
	if (j < 0 || j > 255)
		ft_file_error("rgb value illegal.\n");
	i = shift_left(j, 16);
	if (rgb[1] == NULL || !ft_isdigit(rgb[1][0]))
		ft_file_error("rgb value illegal.\n");
	j = ft_atoi(rgb[1]);
	if (j < 0 || j > 255)
		ft_file_error("rgb value illegal.\n");
	i |= shift_left(j, 8);
	if (rgb[2] == NULL || !ft_isdigit(rgb[2][0]))
		ft_file_error("rgb value illegal.\n");
	j = ft_atoi(rgb[2]);
	if (j < 0 || j > 255)
		ft_file_error("rgb value illegal.\n");
	ft_free_double_ptr(&rgb);
	free(rgb);
	return (i |= j);
}
