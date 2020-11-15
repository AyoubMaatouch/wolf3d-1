/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:45:02 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/15 14:48:21 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_image(void)
{
	int		fd;
	char	*image_name;

	image_name = ft_strdup("screenshot.bmp");
	if ((fd = open(image_name,O_TRUNC | O_WRONLY | O_CREAT, 400)) < 0)
		ft_sys_error(image_name);
}
