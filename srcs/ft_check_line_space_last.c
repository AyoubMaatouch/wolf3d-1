/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_space_last.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:35:06 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/29 22:57:33 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

void	ft_check_line_space_last(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[--i] == ' ')
		ft_file_error("Space(s) in the last of the line.\n");
}
