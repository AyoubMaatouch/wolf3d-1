/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:57:16 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/29 22:47:23 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

/*
** Read the str and give the path of the texture.
*/

char	*get_texture(char *str)
{
	char	**parts;
	char	*texture;
	int		i;

	i = 0;
	ft_check_line_space_last(str);
	parts = ft_split(str, ' ');
	while (parts[i++])
		;
	if (i < 3)
		ft_file_error("Something wrong in texture line.\n");
	i = 0;
	while (ft_isalpha(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	texture = ft_strdup(&str[i]);
	ft_free_double_ptr(&parts);
	return (texture);
}
