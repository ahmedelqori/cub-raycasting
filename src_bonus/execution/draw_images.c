/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 03:53:38 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/14 03:54:10 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	helpdraw(t_container *game);
int		img_px(t_texturedata img, int x, int y);
void	helpdraw2(t_container *game, int x, int y);
void	paint_on_screen_by_pixel(t_texturedata *img, int x, int y, int color);

void	draw_images_to_game(t_container *game, int x)
{
	int		y;
	double	step;
	int		tex_height;

	tex_height = game->bundles.walls.orientations[0].height;
	y = game->bundles.walls.drawstart;
	helpdraw(game);
	step = 1.0 * tex_height / game->bundles.walls.lineheight;
	game->bundles.walls.texy = (game->bundles.walls.drawstart - SCREEN_HEIGHT
			/ 2 + game->bundles.walls.lineheight / 2) * step;
	while (y < game->bundles.walls.drawend)
	{
		game->bundles.walls.texy += step;
		helpdraw2(game, x, y);
		y++;
	}
}

void	helpdraw(t_container *game)
{
	int	tex_width;

	tex_width = game->bundles.walls.orientations[0].width;
	if (game->player.side == 0)
		game->bundles.walls.wallx = game->player.pos.vert
			+ game->player.perpwalldist * game->player.ray.vert;
	else
		game->bundles.walls.wallx = game->player.pos.horz
			+ game->player.perpwalldist * game->player.ray.horz;
	game->bundles.walls.wallx -= floor(game->bundles.walls.wallx);
	game->bundles.walls.texx = (int)(game->bundles.walls.wallx
			* (double)tex_width);
	if (game->player.side == 1 && game->player.ray.vert > 0)
		game->bundles.walls.texx = tex_width - game->bundles.walls.texx - 1;
	if (game->player.side == 0 && game->player.ray.horz < 0)
		game->bundles.walls.texx = tex_width - game->bundles.walls.texx - 1;
}

int	img_px(t_texturedata img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_length)
			+ (x * img.bits_per_pixel / 8))));
}

void	paint_on_screen_by_pixel(t_texturedata *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00980088 || color == (int)16711935)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	helpdraw2(t_container *game, int x, int y)
{
	if (game->player.side == 0 && game->player.ray.horz > 0)
		paint_on_screen_by_pixel(&game->bundles.background, x, y,
			img_px(game->bundles.walls.orientations[2],
				game->bundles.walls.texx, game->bundles.walls.texy));
	else if (game->player.side == 0 && game->player.ray.horz < 0)
		paint_on_screen_by_pixel(&game->bundles.background, x, y,
			img_px(game->bundles.walls.orientations[3],
				game->bundles.walls.texx, game->bundles.walls.texy));
	else if (game->player.side == 1 && game->player.ray.vert < 0)
		paint_on_screen_by_pixel(&game->bundles.background, x, y,
			img_px(game->bundles.walls.orientations[0],
				game->bundles.walls.texx, game->bundles.walls.texy));
	else if (game->player.side == 1 && game->player.ray.vert > 0)
		paint_on_screen_by_pixel(&game->bundles.background, x, y,
			img_px(game->bundles.walls.orientations[1],
				game->bundles.walls.texx, game->bundles.walls.texy));
}
