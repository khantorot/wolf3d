/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:16:49 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/28 09:31:56 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_window(t_wolf *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putstr("Error init_SDL\n");
		exit(1);
	}
	sdl->window = SDL_CreateWindow("Wolf", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE);
	if (!(sdl->window))
	{
		ft_putstr("Window Error\n");
		exit(1);
	}
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, 0);
	if (!sdl->renderer)
	{
		ft_putstr("Error Renderer\n");
		exit(1);
	}
	SDL_SetRenderDrawBlendMode(sdl->renderer, SDL_BLENDMODE_BLEND);
}

void	destroy_window(t_wolf *sdl)
{
	int i;

	i = 0;
	while (sdl->map[i])
	{
		free(sdl->map[i]);
		i++;
	}
	free(sdl->map);
	free(sdl->color_buf);
	free(sdl->wall_text);
	SDL_RenderClear(sdl->renderer);
	SDL_DestroyTexture(sdl->color_buf_text);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
	exit(0);
}
