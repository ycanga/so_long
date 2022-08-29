/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:34:00 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/29 03:38:14 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_argv_control(void)
{
	int		index;
	int		player;
	int		exit;
	int		last_char;
	int		map_height;
	char	**map_char;

	index = 0;
	player = 0;
	exit = 0;
	map_height = win->mapp->height;
	last_char = win->mapp->width - 1;
	map_char = win->mapp->map;
	ft_printf("%d", win->mapp->height);
	while (last_char > 0)
	{
		if (index != map_height)
		{
			if (map_char[][last_char] == 'E' )
			break; // düzeltme
		}
		
		last_char--;
	}
	ft_printf("%d\n%d\n", player, exit);
}

void	map_wall_control(void)
{
	int		last_char;
	int		map_height;
	char	**map_char;
	
	map_height = win->mapp->height;
	last_char = win->mapp->width - 1;
	map_char = win->mapp->map;
	while (last_char > 0)
	{
		if (map_char[0][last_char] == '1' \
			 && map_char[map_height-1][last_char] == '1')
			win->mapp->map_true = 1;
		else
		{
			win->mapp->map_true = 0;
			break;
		}
		last_char--;
	}
	map_argv_control();
}

void	map_argv(void)
{
	int		count;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = win->mapp->fd;
	line = get_next_line(fd);
	if (line == 0)
		ft_printf("Invalid map size");
	win->mapp->width = ft_strlen(line)-1;
	count = 0;
	while (line)
	{
		win->mapp->map[i] = ft_calloc(win->mapp->width, 1);
		ft_strlcpy(win->mapp->map[i], line, win->mapp->width +1);
		i++;
		free(line);
		line = get_next_line(fd);
		count++;
	}
	win->mapp->height = count;
	wall_control();
	ft_printf("map control: %d", win->mapp->map_true);
	free(line);
}

void	wall_control(void)
{
	int		start;
	int		last;
	char	**map_char;

	win->mapp->map_true = 1;
	map_char = win->mapp->map;
	start = win->mapp->height;
	last = win->mapp->width;
	while (start--)
	{
		if (map_char[start][0] == '1' && map_char[start][last - 1] == '1')
			win->mapp->map_true = 1;
		else
		{
			ft_printf("Map error.\t");
			win->mapp->map_true = 0;
			break;
		}
	}
	map_wall_control();
}

void	read_map(char *maps)
{
	int		fd;

	if (maps)
	{
		fd = open(maps, O_RDONLY);
		win->mapp->fd = fd;
		if (fd < 0)
			ft_printf("Invalid map");
		map_argv();
		close(fd);
	}
	else
		ft_printf("Error Maps");
}
