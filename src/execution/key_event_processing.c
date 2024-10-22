/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:13:40 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/22 16:44:54 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	*array_of_direction(void);
static int	key_press(int key, t_container *container);
static int	key_release(int key, t_container *container);

void	handle_events(t_container *container)
{
	mlx_hook(container->win, 17, 0, mouse_hook, container);
	mlx_hook(container->win, 2, 1L << 0, key_press, container);
	mlx_hook(container->win, 3, 1L << 1, key_release, container);
	mlx_hook(container->win, 6, 1L << 6, handle_mouse, container);
	mlx_mouse_hide(container->mlx, container->win);
}

static int	key_press(int key, t_container *container)
{
	6[(int *)(array_of_direction())] = -1;
	if (key == ESC)
		terminate_with_cleanup(key, container);
	while (++6[(int *)(array_of_direction())] < 6)
		if (key == ((int *)(array_of_direction())) \
			[6[(int *)(array_of_direction())]])
			container->mouvements[6[(int *)(array_of_direction())]] = TRUE;
	return (1);
}

static int	key_release(int key, t_container *container)
{
	6[(int *)(array_of_direction())] = -1;
	if (key == ESC)
		terminate_with_cleanup(key, container);
	while (++6[(int *)(array_of_direction())] < 6)
		if (key == ((int *)(array_of_direction())) \
			[6[(int *)(array_of_direction())]])
			container->mouvements[6[(int *)(array_of_direction())]] = FALSE;
	return (1);
}

static int	*array_of_direction(void)
{
	static int	keys[7] = {KEY_W, KEY_S, KEY_A, KEY_D,
		ARROW_LEFT, ARROW_RIGHT, -1};

	return (keys);
}
