/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:26:37 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/25 18:37:17 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	cast_loop(t_cast *a, t_wolf *sdl)
{
	while (a->next_horz_touch_x >= 0 && a->next_horz_touch_x <= WINDOW_WIDTH &&
			a->next_horz_touch_y >= 0 && a->next_horz_touch_y <= WINDOW_HEIGHT)
	{
		a->x_to_check = a->next_horz_touch_x;
		a->y_to_check = a->next_horz_touch_y + (a->ray_face_up ? -1 : 0);
		if (map_has_wall(a->y_to_check, a->x_to_check, sdl))
		{
			a->horz_wall_hit_x = a->next_horz_touch_x;
			a->horz_wall_hit_y = a->next_horz_touch_y;
			a->horz_wall_content = sdl->map[(int)floor(a->y_to_check /
				sdl->tile_size)][(int)floor(a->x_to_check / sdl->tile_size)];
			a->horz_wall_hit = 1;
			break ;
		}
		else
		{
			a->next_horz_touch_x += a->x_step;
			a->next_horz_touch_y += a->y_step;
		}
	}
}

void	init_cast_2(t_cast *a, t_wolf *sdl, t_player *player, double ray_angle)
{
	a->x_inter = floor(player->x / sdl->tile_size) * sdl->tile_size;
	a->x_inter += a->ray_face_right ? sdl->tile_size : 0;
	a->y_inter = player->y + (a->x_inter - player->x) * tan(ray_angle);
	a->x_step = sdl->tile_size;
	a->x_step *= a->ray_face_left ? -1 : 1;
	a->y_step = sdl->tile_size * tan(ray_angle);
	a->y_step *= (a->ray_face_up && a->y_step > 0) ? -1 : 1;
	a->y_step *= (a->ray_face_down && a->y_step < 0) ? -1 : 1;
	a->next_vert_touch_x = a->x_inter;
	a->next_vert_touch_y = a->y_inter;
}

void	cast_loop_2(t_cast *a, t_wolf *sdl)
{
	while (a->next_vert_touch_x >= 0 && a->next_vert_touch_x <= WINDOW_WIDTH &&
			a->next_vert_touch_y >= 0 && a->next_vert_touch_y <= WINDOW_HEIGHT)
	{
		a->x_to_check = a->next_vert_touch_x + (a->ray_face_left ? -1 : 0);
		a->y_to_check = a->next_vert_touch_y;
		if (map_has_wall(a->y_to_check, a->x_to_check, sdl))
		{
			a->vert_wall_hit_x = a->next_vert_touch_x;
			a->vert_wall_hit_y = a->next_vert_touch_y;
			a->vert_wall_content = sdl->map[(int)floor(a->y_to_check /
				sdl->tile_size)][(int)floor(a->x_to_check / sdl->tile_size)];
			a->vert_wall_hit = 1;
			break ;
		}
		else
		{
			a->next_vert_touch_x += a->x_step;
			a->next_vert_touch_y += a->y_step;
		}
	}
}

void	fill_ray(t_ray *ray, t_cast *a, double ray_angle)
{
	if (a->vert_hit_distance < a->horz_hit_distance)
	{
		ray->distance = a->vert_hit_distance;
		ray->wall_hit_x = a->vert_wall_hit_x;
		ray->wall_hit_y = a->vert_wall_hit_y;
		ray->was_hit_vertical = 1;
		ray->wall_hit = a->vert_wall_content;
	}
	else
	{
		ray->distance = a->horz_hit_distance;
		ray->wall_hit_x = a->horz_wall_hit_x;
		ray->wall_hit_y = a->horz_wall_hit_y;
		ray->was_hit_vertical = 0;
		ray->wall_hit = a->horz_wall_content;
	}
	ray->ray_angle = ray_angle;
	ray->ray_face_down = a->ray_face_down;
	ray->ray_face_left = a->ray_face_left;
	ray->ray_face_right = a->ray_face_right;
	ray->ray_face_up = a->ray_face_up;
}

void	cast_ray(double ray_angle, t_wolf *sdl, t_player *player, t_ray *ray)
{
	t_cast a[1];

	ray_angle = init_cast(a, sdl, ray_angle, player);
	cast_loop(a, sdl);
	init_cast_2(a, sdl, player, ray_angle);
	cast_loop_2(a, sdl);
	a->horz_hit_distance = a->horz_wall_hit ? distance_between(player->x,
	player->y, a->horz_wall_hit_x, a->horz_wall_hit_y) : 2147483647;
	a->vert_hit_distance = a->vert_wall_hit ? distance_between(player->x,
	player->y, a->vert_wall_hit_x, a->vert_wall_hit_y) : 2147483647;
	fill_ray(ray, a, ray_angle);
}
