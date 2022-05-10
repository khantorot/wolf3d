/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:14:40 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/26 10:34:10 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <unistd.h>
# include <stdio.h>
# include <SDL2/SDL.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 832
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef struct		s_cast
{
	int				ray_face_up;
	int				ray_face_down;
	int				ray_face_left;
	int				ray_face_right;
	float			x_inter;
	float			y_inter;
	float			x_step;
	float			y_step;
	int				horz_wall_hit;
	float			horz_wall_hit_x;
	float			horz_wall_hit_y;
	int				horz_wall_content;
	float			next_horz_touch_x;
	float			next_horz_touch_y;
	float			x_to_check;
	float			y_to_check;
	int				vert_wall_hit;
	float			vert_wall_hit_x;
	float			vert_wall_hit_y;
	int				vert_wall_content;
	float			next_vert_touch_x;
	float			next_vert_touch_y;
	float			horz_hit_distance;
	float			vert_hit_distance;
}					t_cast;

typedef struct		s_wolf
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Rect		rect;
	SDL_Texture		*color_buf_text;
	Uint32			*color_buf;
	Uint32			*wall_text;
	Uint32			*textures[4];
	int				**map;
	double			pi;
	double			two_pi;
	double			fov_angle;
	double			scale_factor;
	int				num_rays;
	int				tile_size;
	int				map_num_row;
	int				map_num_col;
	int				frame_ticks;
}					t_wolf;

typedef struct		s_player
{
	double			x;
	double			y;
	double			width;
	double			height;
	int				turn_direction;
	int				walk_direction;
	double			rotat_angle;
	double			walk_speed;
	double			turn_speed;
}					t_player;

typedef struct		s_ray
{
	double			ray_angle;
	double			wall_hit_x;
	double			wall_hit_y;
	double			distance;
	int				was_hit_vertical;
	int				ray_face_up;
	int				ray_face_down;
	int				ray_face_left;
	int				ray_face_right;
	int				wall_hit;
}					t_ray;

typedef struct		s_projection
{
	int				i;
	int				y;
	int				x;
	int				wall_strip_height;
	int				wall_top_pix;
	int				wall_bot_pix;
	int				text_offset_x;
	int				text_offset_y;
	int				distance_from_top;
	Uint32			texel_color;
	float			distance;
	float			distance_perp;
	float			proj_wall_height;
}					t_projection;

typedef struct		s_map
{
	int				i;
	int				j;
	int				tile_x;
	int				tile_y;
	int				tile_color;
}					t_map;

void				read_map(char	*file, t_wolf *sdl);
void				setup(t_wolf *sdl, t_player *player);
double				init_cast(t_cast *a, t_wolf *sdl,
					double ray_angle, t_player *player);
void				render(t_wolf *sdl, t_player *player, t_ray ray[1280]);
void				check_input(int ac, char **av);
void				init_window(t_wolf *sdl);
void				destroy_window(t_wolf *sdl);
void				process(t_wolf *sdl, t_player *player);
void				update(t_wolf *sdl, t_player *player, t_ray ray[1280]);
void				cast_ray(double ray_angle, t_wolf *sdl,
								t_player *player, t_ray *ray);
int					map_has_wall(float y, float x, t_wolf *sdl);
double				normalize_angle(double angle, t_wolf *sdl);
float				distance_between(float x1, float y1, float x2, float y2);
void				cast_ray(double ray_angle, t_wolf *sdl,
							t_player *player, t_ray *ray);
void				generate_3d_projection(t_wolf *sdl,
						t_ray ray[1280], t_player *player);
#endif
