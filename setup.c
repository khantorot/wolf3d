/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:13:57 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/25 18:59:06 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "textures.h"

void	get_player_pos(t_wolf *sdl, t_player *player)
{
	int y;
	int x;

	x = 1;
	while (x < sdl->map_num_col)
	{
		y = 1;
		while (y < sdl->map_num_row)
		{
			if (sdl->map[y][x] == 0)
			{
				player->x = x * sdl->tile_size + 1;
				player->y = y * sdl->tile_size + 1;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	setup(t_wolf *sdl, t_player *player)
{
	sdl->frame_ticks = 0;
	sdl->pi = 3.14159265;
	sdl->two_pi = 6.28318530;
	sdl->tile_size = 64;
	sdl->fov_angle = 60 * (sdl->pi / 180);
	sdl->num_rays = 1280;
	sdl->scale_factor = 0.27;
	sdl->color_buf = (Uint32 *)malloc(sizeof(Uint32) *
				(Uint32)WINDOW_HEIGHT * (Uint32)WINDOW_WIDTH);
	sdl->color_buf_text = SDL_CreateTexture(sdl->renderer,
										SDL_PIXELFORMAT_ABGR8888,
	SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
	sdl->textures[3] = (Uint32 *)g_dirt;
	sdl->textures[2] = (Uint32 *)g_book;
	sdl->textures[1] = (Uint32 *)g_stone;
	sdl->textures[0] = (Uint32 *)g_wall;
	get_player_pos(sdl, player);
	player->height = 1;
	player->width = 1;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotat_angle = sdl->pi / 2;
	player->walk_speed = 5;
	player->turn_speed = 2 * 45 * (sdl->pi / 180);
}

double	init_cast(t_cast *a, t_wolf *sdl, double ray_angle, t_player *player)
{
	a->horz_wall_hit_x = 0;
	a->horz_wall_hit_y = 0;
	a->horz_wall_hit = 0;
	a->horz_wall_content = 0;
	a->vert_wall_hit_x = 0;
	a->vert_wall_hit_y = 0;
	a->vert_wall_hit = 0;
	a->vert_wall_content = 0;
	ray_angle = normalize_angle(ray_angle, sdl);
	a->ray_face_down = ray_angle > 0 && ray_angle < sdl->pi;
	a->ray_face_up = !a->ray_face_down;
	a->ray_face_right = ray_angle < 0.5 * sdl->pi || ray_angle > 1.5 * sdl->pi;
	a->ray_face_left = !a->ray_face_right;
	a->y_inter = floor(player->y / sdl->tile_size) * sdl->tile_size;
	a->y_inter += a->ray_face_down ? sdl->tile_size : 0;
	a->x_inter = player->x + (a->y_inter - player->y) / tan(ray_angle);
	a->y_step = sdl->tile_size;
	a->y_step *= a->ray_face_up ? -1 : 1;
	a->x_step = sdl->tile_size / tan(ray_angle);
	a->x_step *= (a->ray_face_left && a->x_step > 0) ? -1 : 1;
	a->x_step *= (a->ray_face_right && a->x_step < 0) ? -1 : 1;
	a->next_horz_touch_x = a->x_inter;
	a->next_horz_touch_y = a->y_inter;
	return (ray_angle);
}
