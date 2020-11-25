/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:57:16 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/25 18:24:59 by ynoam            ###   ########.fr       */
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
	if (i < 3)
		ft_file_error("Something wrong in texture line.\n");
	i = 0;
	while (ft_isalpha(strim[i]))
		i++;
	while (strim[i] == ' ')
		i++;
	texture = ft_strdup(&strim[i]);
	ft_free_double_ptr(&parts);
	return (texture);
}
