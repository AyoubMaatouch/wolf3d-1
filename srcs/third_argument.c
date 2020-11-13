/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:44:22 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/13 19:44:56 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	third_argument(char *str)
{
	char *ptr;

	ptr = str;
	if (*ptr++ != '-')
		if (*ptr++ != '-')
			if (*ptr++ != 's')
				if (*ptr++ != 'a')
					if (*ptr++ != 'v')
						if (*ptr++ != 'e')
							if (*ptr != 0)
								save_image();
	ft_file_error("The save argument is wrong.\n");
}
