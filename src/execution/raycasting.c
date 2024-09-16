/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:42:03 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/14 04:06:32 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void		check_hit(t_container *game);
static int		map_size(char **str);

void	digital_differential_analysis(t_container *game)
{
	game->player.x = 0;
	while (game->player.x < SCREEN_WIDTH)
	{
		calc_ray_for_y_x(game);
		calc_step_for_y_x(game);
		check_hit(game);
		calculate_camera_direction(game);
		draw_images_to_game(game, game->player.x);
		game->player.hit = 0;
		game->player.x++;
	}
}

static int	map_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	check_hit(t_container *game)
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
			game->player.mapy >= map_size(game->data->map) || \
			game->player.mapx >= (int)ft_strlen(
				game->data->map[game->player.mapy]))
			game->player.hit = 2;
		else if (game->data->map[game->player.mapy][game->player.mapx] == '1')
			game->player.hit = 1;
	}
}
