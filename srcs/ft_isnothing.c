/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnothing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:57:51 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/30 18:34:47 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

void	ft_isnothing(char *line)
{
	if (line[0] == '\0')
		ft_free(&line);
	else
		ft_file_error("Something wrong in the data part.\n");
}
