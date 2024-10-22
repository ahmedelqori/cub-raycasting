/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:17:34 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/22 16:44:16 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	handle_mouse(int x, int y, t_container *container)
{
	static int	win[2] = {START, START};
	int			center[2];
	int			delta;

	if (WX[win] == -1 && WY[win] == -1)
		mlx_get_screen_size(container->mlx, &WX[win], &WY[win]);
	CX[center] = WX[win] / 2;
	CY[center] = WY[win] / 2;
	delta = x - CX[center];
	if (delta != 0)
		camera_left_right(container, delta * MOUSE_SENSITIVITY);
	mlx_mouse_move(container->mlx, container->win, CX[center], CY[center]);
	return (y);
}
