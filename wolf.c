/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:14:25 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/27 11:27:26 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_wolf		sdl[1];
	t_player	player[1];
	t_ray		ray[1280];

	check_input(ac, av);
	read_map(av[1], sdl);
	init_window(sdl);
	setup(sdl, player);
	while (1)
	{
		process(sdl, player);
		update(sdl, player, ray);
		render(sdl, player, ray);
	}
	destroy_window(sdl);
	return (0);
}
