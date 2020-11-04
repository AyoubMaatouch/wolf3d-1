/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:57:16 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/04 16:35:02 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

/*
** Read the strim and give the path of the texture.
*/

char	*get_texture(char *strim)
{
	char	**parts;
	char	*texture;
	int		i;

	i = 0;
	parts = ft_split(strim, ' ');
	while (parts[i++])
		;
	if (i != 3)
		ft_file_error("Something wrong in texture line.\n");
	texture = ft_strdup(parts[1]);
	ft_free_double_ptr(&parts);
	return (texture);
}
