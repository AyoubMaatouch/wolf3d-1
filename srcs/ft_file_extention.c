/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_extention.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:39:41 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/02 14:24:49 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int	ft_file_extention(const char *filename, char *str)
{
	int i;
	int j;

	j = ft_strlen(filename) - 1;
	if (j > 4)
	{
		i = j - 3;
		if (filename[i++] == str[0])
			if (filename[i++] == str[1])
				if (filename[i++] == str[2])
					if (filename[i++] == str[3])
						return (0);
	}
	ft_my_errors("filename extension not correct.");
	return (1);
}
