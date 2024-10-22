/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:39:31 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/22 21:49:20 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

int	update_render(t_container *container)
{
	draw_floor_ceil(container);
	digital_differential_analysis(container);
	handle_movement(container);
	return (SUCCESS);
}