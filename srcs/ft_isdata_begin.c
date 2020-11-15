/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdata_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:40:28 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/15 14:14:09 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int	ft_isdata_begin(char *line)
{
	int i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isalpha(line[i]))
		return (1);
	return (0);
}
