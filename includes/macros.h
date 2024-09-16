/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:16:18 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/16 13:16:36 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "cub.h"

// ================== Colors =============

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BOLDBLACK "\033[1m\033[30m"
# define BOLDRED "\033[1m\033[31m"
# define BOLDGREEN "\033[1m\033[32m"
# define BOLDYELLOW "\033[1m\033[33m"
# define BOLDBLUE "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN "\033[1m\033[36m"
# define BOLDWHITE "\033[1m\033[37m"

// ================== Status =============

# define FAIL -1 // check error
# define SUCCESS 0

# define TRUE 1
# define FALSE 0

# define INDEX 0
// ================== Game =============

# define NAME "CUB"
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 768

# define NORTH 'N'
# define SOUTH 'S'
# define WEST  'W'
# define EAST  'E'

# define X 'x'
# define Y 'y'

# define NORTH_X 0.0f
# define NORTH_Y -1.0f
# define SOUTH_X 0.0f
# define SOUTH_Y 1.0f
# define EAST_X 1.0f
# define EAST_Y 0.0f
# define WEST_X -1.0f
# define WEST_Y 0.0f

# define MOVE_SPEED 0.08f
# define ROTATION_SPEED 0.01f

# define DISTANCE_IN_FORWARD -0.22f
# define DISTANCE_IN_BACKWARD 0.8f
# define DISTANCE_IN_LEFT -0.1f
# define DISTANCE_IN_RIGHT 0.15f

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ESC 65307

# define UP 'W'
# define DOWN 'S'
# define LEFT 'A'
# define RIGHT 'D'
# define CAMERA_LEFT 'L'
# define CAMERA_RIGHT 'R'

# define WALL '1'

// tmp
# define MAXDOUBLE 1e30

// ================== ERRORS =============

# define ALLOC_CONTAINER "Failed Allocation of container"

// =================PARSING=====================

#ifndef MAX_LINE
#define MAX_LINE 4096
#endif


#endif
