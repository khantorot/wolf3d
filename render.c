/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:10:55 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/27 11:43:57 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	render_player(t_wolf *sdl, t_player *player)
{
	SDL_Rect player_rect;

	SDL_SetRenderDrawColor(sdl->renderer, 251, 25, 25, 255);
	player_rect.x = player->x * sdl->scale_factor;
	player_rect.y = player->y * sdl->scale_factor;
	player_rect.w = player->width * sdl->scale_factor;
	player_rect.h = player->height * sdl->scale_factor;
	SDL_RenderFillRect(sdl->renderer, &player_rect);
	SDL_RenderDrawLine(sdl->renderer, player->x * sdl->scale_factor,
										player->y * sdl->scale_factor,
	sdl->scale_factor * player->x + cos(player->rotat_angle) * 10,
	sdl->scale_factor * player->y + sin(player->rotat_angle) * 10);
}

void	render_rays(t_wolf *sdl, t_ray ray[1280], t_player *player)
{
	int i;

	i = 0;
	SDL_SetRenderDrawColor(sdl->renderer, 76, 0, 153, 255);
	while (i < sdl->num_rays)
	{
		SDL_RenderDrawLine(sdl->renderer, sdl->scale_factor * player->x,
		sdl->scale_factor * player->y, sdl->scale_factor * ray[i].wall_hit_x,
		sdl->scale_factor * ray[i].wall_hit_y);
		i++;
	}
}

void	render_map(t_wolf *sdl)
{
	t_map		map[1];
	SDL_Rect	map_tile_rect;

	map->i = 0;
	while (map->i < sdl->map_num_row)
	{
		map->j = 0;
		while (map->j < sdl->map_num_col)
		{
			map->tile_x = map->j * sdl->tile_size;
			map->tile_y = map->i * sdl->tile_size;
			map->tile_color = sdl->map[map->i][map->j] != 0 ? 255 : 0;
			SDL_SetRenderDrawColor(sdl->renderer, map->tile_color,
							map->tile_color, map->tile_color, map->tile_color);
			map_tile_rect.x = map->tile_x * sdl->scale_factor;
			map_tile_rect.y = map->tile_y * sdl->scale_factor;
			map_tile_rect.w = sdl->tile_size * sdl->scale_factor;
			map_tile_rect.h = map_tile_rect.w;
			SDL_RenderFillRect(sdl->renderer, &map_tile_rect);
			map->j++;
		}
		map->i++;
	}
}

void	clear_color_buf(Uint32 color, t_wolf *sdl)
{
	int x;
	int y;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			sdl->color_buf[WINDOW_WIDTH * y + x] = color;
			y++;
		}
		x++;
	}
}

void	render(t_wolf *sdl, t_player *player, t_ray ray[1280])
{
	generate_3d_projection(sdl, ray, player);
	SDL_UpdateTexture(sdl->color_buf_text, NULL, sdl->color_buf,
					(int)((Uint32)WINDOW_WIDTH * sizeof(Uint32)));
	SDL_RenderCopy(sdl->renderer, sdl->color_buf_text, NULL, NULL);
	render_map(sdl);
	render_rays(sdl, ray, player);
	render_player(sdl, player);
	SDL_RenderPresent(sdl->renderer);
}
