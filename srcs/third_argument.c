/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:44:22 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/15 14:47:36 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	third_argument(char *str)
{
	if (ft_memcmp(str, "--save", 7) == 0)
		save_image();
	//ft_file_error("The save argument is wrong.\n");
}
