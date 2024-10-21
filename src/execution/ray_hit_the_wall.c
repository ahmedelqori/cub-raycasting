/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_the_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:06:34 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/21 16:09:01 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	get_size_of_matrix(char **str);

void	check_hit(t_container *game)
{
	while (game->player.hit == 0)
	{
		if (game->player.sidedist.horz < game->player.sidedist.vert)
		{
			game->player.sidedist.horz += game->player.delta.horz;
			game->player.mapx += game->player.stepx;
			game->player.side = 0;
		}
		else
		{
			game->player.sidedist.vert += game->player.delta.vert;
			game->player.mapy += game->player.stepy;
			game->player.side = 1;
		}
		if (game->player.mapx < 0 || game->player.mapy < 0 || \
			game->player.mapy >= get_size_of_matrix(game->data->map) || \
			game->player.mapx >= (int)ft_strlen(
				game->data->map[game->player.mapy]))
			game->player.hit = 2;
		else if (game->data->map[game->player.mapy][game->player.mapx] == '1')
			game->player.hit = 1;
	}
}

static int	get_size_of_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
