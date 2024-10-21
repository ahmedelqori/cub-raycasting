/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:39:31 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/11 14:54:32 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	update_render(t_container *container)
{
	draw_floor_ceil(container);
	handle_movement(container);
	digital_differential_analysis(container);
	return (SUCCESS);
}
