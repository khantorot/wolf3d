/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:01:19 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/28 10:08:37 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	generate_3d_projection_1(t_wolf *sdl, t_ray ray[1280],
								t_player *player, t_projection *p)
{
	p->distance_perp = ray[p->i].distance * cos(ray[p->i].ray_angle -
											player->rotat_angle);
	p->distance = (WINDOW_WIDTH / 2) / tan(sdl->fov_angle / 2);
	p->proj_wall_height = (sdl->tile_size / p->distance_perp) * p->distance;
	p->wall_strip_height = (int)p->proj_wall_height;
	p->wall_top_pix = (WINDOW_HEIGHT / 2) - (p->wall_strip_height / 2);
	p->wall_top_pix = p->wall_top_pix < 0 ? 0 : p->wall_top_pix;
	p->wall_bot_pix = (WINDOW_HEIGHT / 2) + (p->wall_strip_height / 2);
	p->wall_bot_pix = p->wall_bot_pix > WINDOW_HEIGHT ? WINDOW_HEIGHT :
													p->wall_bot_pix;
	p->y = 0;
	while (p->y < p->wall_top_pix)
	{
		sdl->color_buf[WINDOW_WIDTH * p->y + p->i] = 0xFF0080FF;
		p->y++;
	}
	p->y = p->wall_top_pix;
	if (ray[p->i].was_hit_vertical == 1)
		p->text_offset_x = (int)ray[p->i].wall_hit_y % sdl->tile_size;
	else
		p->text_offset_x = (int)ray[p->i].wall_hit_x % sdl->tile_size;
}

void	fill_color_buf(t_wolf *sdl, t_projection *p)
{
	while (p->y < WINDOW_HEIGHT)
	{
		sdl->color_buf[WINDOW_WIDTH * p->y + p->i] = 0xFF777777;
		p->y++;
	}
}

void	generate_3d_projection(t_wolf *sdl, t_ray ray[1280], t_player *player)
{
	t_projection	p;
	Uint32			texel_color;
	int				text_num;

	p.i = 0;
	while (p.i < sdl->num_rays)
	{
		generate_3d_projection_1(sdl, ray, player, &p);
		text_num = ray[p.i].wall_hit - 1;
		while (p.y < p.wall_bot_pix)
		{
			p.distance_from_top = p.y + (p.wall_strip_height / 2) -
												(WINDOW_HEIGHT / 2);
			p.text_offset_y = p.distance_from_top *
				((float)TEXTURE_HEIGHT / p.wall_strip_height);
			texel_color = sdl->textures[text_num][(TEXTURE_HEIGHT
							* p.text_offset_y) + p.text_offset_x];
			sdl->color_buf[(WINDOW_WIDTH * p.y) + p.i] = texel_color;
			p.y++;
		}
		p.y = p.wall_bot_pix;
		fill_color_buf(sdl, &p);
		p.i++;
	}
}
