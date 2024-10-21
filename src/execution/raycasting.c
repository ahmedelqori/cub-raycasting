/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:42:03 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/21 16:09:05 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
