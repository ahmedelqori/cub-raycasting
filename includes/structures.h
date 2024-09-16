/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:15:54 by ael-qori          #+#    #+#             */
/*   Updated: 2024/09/16 13:02:41 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub.h"

// ================ PARSING PART ================ //

typedef struct s_parsing
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	unsigned int	floor;
	unsigned int	ceil;
	char			**map;
	int				map_x;
	int				map_y;
	char			direction;
}	t_parsing;

// ================ EXECUTION PART ================ //

typedef struct s_vector
{
	double	horz;
	double	vert;
}	t_vector;

typedef struct s_playerentity
{
	int			x;
	int			hit;
	int			mapx;
	int			mapy;
	int			side;
	int			stepy;
	int			stepx;
	double		camerax;
	double		perpwalldist;
	t_vector	dir;
	t_vector	pos;
	t_vector	pln;
	t_vector	ray;
	t_vector	sidedist;
	t_vector	delta;
}	t_playerentity;

typedef struct s_colorpalette
{
	int	ceil_rgb[3];
	int	floor_rgb[3];
}	t_colorpalette;

typedef struct s_texturedata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texturedata;

typedef struct s_wallproperties
{
	double			wallx;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texx;
	double			texy;
	t_texturedata	orientations[6];
}	t_wallproperties;

typedef struct s_graphicsbundle
{
	t_texturedata		background;
	t_wallproperties	walls;
}	t_graphicsbundle;

typedef struct s_container
{
	void				*mlx;
	void				*win;
	bool				mouvements[6];
	t_parsing			*data;
	t_playerentity		player;
	t_colorpalette		background;
	t_graphicsbundle	bundles;
}	t_container;

#endif
