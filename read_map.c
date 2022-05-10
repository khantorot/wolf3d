/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 12:13:01 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/28 09:51:10 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		get_height(char *file)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int		get_width(char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		res;
	char	**tmp;

	i = -1;
	res = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	tmp = ft_strsplit(line, ' ');
	while (tmp[++i])
	{
		res++;
		free(tmp[i]);
	}
	free(tmp);
	free(line);
	close(fd);
	return (res);
}

int		*fill_map(char *line, int *map_line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
	{
		map_line[i] = ft_atoi(tmp[i]);
		if (map_line[i] > 4 && map_line[i] < 9)
			map_line[i] = 2;
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (map_line);
}

void	read_map(char *file, t_wolf *sdl)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	sdl->map_num_col = get_width(file);
	sdl->map_num_row = get_height(file);
	sdl->map = (int **)malloc(sizeof(int *) * sdl->map_num_row);
	fd = open(file, O_RDONLY);
	while (i < sdl->map_num_row && get_next_line(fd, &line) > 0)
	{
		sdl->map[i] = (int *)malloc(sizeof(int) * sdl->map_num_col);
		sdl->map[i] = fill_map(line, sdl->map[i]);
		free(line);
		i++;
	}
	close(fd);
}
