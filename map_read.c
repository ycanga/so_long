/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:10:38 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/16 16:30:33 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *maps, t_win *win)
{
	int		fd;

	if (maps)
	{
		fd = open(maps, O_RDONLY);
		if (fd < 0)
			ft_error(win, 7);
		else
			win->mapp->fd = fd;
		map_argv(win);
		close(fd);
	}
	else
		ft_error(win, 0);
}

void	map_argv(t_win *win)
{
	int		count;
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(win->mapp->fd);
	if (line == 0)
		ft_error(win, 1);
	win->mapp->width = ft_strlen(line) - 1;
	count = 0;
	while (line)
	{
		win->mapp->map[i] = ft_calloc(win->mapp->width, 1);
		ft_strlcpy(win->mapp->map[i], line, (int)ft_strlen(line) + 1);
		if ((int)ft_strlen(win->mapp->map[i]) - 1 != win->mapp->width)
			ft_error(win, 0);
		free(line);
		line = get_next_line(win->mapp->fd);
		count++;
		i++;
	}
	win->mapp->height = count;
	win->mapp->valid_map = ft_calloc(sizeof(char *) * win->mapp->height, 1);
	free(line);
	wall_control(win);
}

void	wall_control(t_win *win)
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
			win->mapp->map_true = 0;
			ft_error(win, 0);
		}
	}
	if (win->mapp->map_true == 1)
		map_wall_control(win);
}

void	map_wall_control(t_win *win)
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
		&& map_char[map_height - 1][last_char] == '1')
			win->mapp->map_true = 1;
		else
		{
			win->mapp->map_true = 0;
			ft_error(win, 0);
		}
		last_char--;
	}
	map_argv_control(win);
}

void	map_argv_control(t_win *win)
{
	int		i;
	int		j;
	char	**map;

	win->mapp->exit = 0;
	map = win->mapp->map;
	i = -1;
	while (++i < win->mapp->height)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				win->mapp->exit += 1;
			if (map[i][j] == 'P')
			{
				win->mapp->player_i = i;
				win->mapp->player_j = j;
				win->mapp->player += 1;
			}
			if (map[i][j] == 'C')
				win->mapp->collect += 1;
		}
	}
	argv_control(win);
}
