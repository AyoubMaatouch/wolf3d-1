/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:31:44 by ynoam             #+#    #+#             */
/*   Updated: 2020/11/04 16:26:29 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

/*
** print the error and exit the programme;
*/

int	ft_file_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("cub3d: ", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
	return (1);
}
