/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:15:05 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/14 21:04:40 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "cub.h"

// ======================= PARSING ======================= //

t_parsing	*ft_paring(void);
void		ft_free_parsing(t_parsing *data);

// ======================= EXECUTION ======================= //
void		ft_execute(t_parsing *parsing);
void		safe_exit(t_parsing *parsing, int status, char *error);
void		initialize_defaults(t_container *container);
int			terminate_with_cleanup(int key, t_container *container);
void		handle_events(t_container *container);
int			update_render(t_container *cub);
void		initialize_images(t_container *container);
void		initialize_to_zero(t_container *container);
void		handle_movement(t_container *container);
void		draw_floor_ceil(t_container *container);
void		calc_ray_for_y_x(t_container *container);
void		calculate_camera_direction(t_container *game);
void		calc_step_for_y_x(t_container *container);
void		draw_images_to_game(t_container *game, int x);
void		digital_differential_analysis(t_container *game);
#endif
