/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:22:14 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/25 14:12:15 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	cast_all_rays(t_ray ray[1280], t_player *player, t_wolf *sdl)
{
	double	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = player->rotat_angle - (sdl->fov_angle / 2);
	while (strip_id < sdl->num_rays)
	{
		cast_ray(ray_angle, sdl, player, &ray[strip_id]);
		ray_angle += sdl->fov_angle / sdl->num_rays;
		strip_id++;
	}
}

void	move_player(t_wolf *sdl, t_player *player, float delta_time)
{
	float move_step;
	float new_player_x;
	float new_player_y;

	player->rotat_angle += player->turn_direction * player->turn_speed
													* delta_time;
	move_step = player->walk_direction * player->walk_speed;
	new_player_x = player->x + cos(player->rotat_angle) * move_step;
	new_player_y = player->y + sin(player->rotat_angle) * move_step;
	if (!(map_has_wall(new_player_y, new_player_x, sdl)))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}

void	update(t_wolf *sdl, t_player *player, t_ray ray[1280])
{
	float	delta_time;
	float	frame_time;

	frame_time = 1000 / 30;
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), sdl->frame_ticks + frame_time))
		;
	delta_time = (SDL_GetTicks() - sdl->frame_ticks) / 1000.0;
	sdl->frame_ticks = SDL_GetTicks();
	move_player(sdl, player, delta_time);
	cast_all_rays(ray, player, sdl);
}
