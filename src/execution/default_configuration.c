/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_defaults.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:11:52 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/11 15:00:40 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void		resolveorientation(t_container *container, int index);
static char		*getorientation(void);
static double	*getdirections(int vh);
static double	*getplane(int vh);

void	initialize_defaults(t_container *container)
{
	int	index;

	container->player.pos.horz = container->data->map_x + 0.5f;
	container->player.pos.vert = container->data->map_y + 0.5f;
	index = 0;
	while (index != 3)
	{
		container->background.ceil_rgb[index] = FAIL;
		container->background.floor_rgb[index++] = FAIL;
	}
	resolveorientation(container, INDEX);
	initialize_images(container);
	container->player.sidedist.horz = 2;
	container->player.sidedist.vert = 2;
	container->player.hit = 0;
}

static void	resolveorientation(t_container *container, int index)
{
	while (index[(char *)getorientation()])
	{
		if (index[(char *)getorientation()] == container->data->direction)
		{
			container->player.dir.horz = index[(double *)getdirections(X)];
			container->player.dir.vert = index[(double *)getdirections(Y)];
			container->player.pln.horz = index[(double *)getplane(X)];
			container->player.pln.vert = index[(double *)getplane(Y)];
		}
		index++;
	}
}

static char	*getorientation(void)
{
	static char	direction[5] = {EAST, WEST, NORTH, SOUTH, '\0'};

	return (direction);
}

static double	*getdirections(int vh)
{
	static double	horz_dir[4] = {1.0f, -1.0f, 0.0f, 0.0f};
	static double	vert_dir[4] = {0.0f, 0.0f, -1.0f, 1.0f};

	if (vh == X)
		return (horz_dir);
	return (vert_dir);
}

static double	*getplane(int vh)
{
	static double	horz_plane[4] = {0, 0, 0.66, -0.66};
	static double	vert_plane[4] = {0.66, -0.66, 0, 0};

	if (vh == X)
		return (horz_plane);
	return (vert_plane);
}