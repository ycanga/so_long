/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:10:38 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/10 18:27:20 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *maps, t_win *win)
{
	int		fd;

	if (maps)
	{
		fd = open(maps, O_RDONLY);
		win->mapp->fd = fd;
		if (fd < 0)
			ft_printf("\033[31mFile Not Found. !\n");
		map_argv(win);
		close(fd);
	}
	else
		ft_printf("\033[31mError Maps\n");
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
	win->mapp->map[i] = NULL;
	win->mapp->height = count;
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
			ft_printf("\033[31mMap error.\t");
			win->mapp->map_true = 0;
			break ;
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
			break ;
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

	map = win->mapp->map;
	i = 0;
	while (i < win->mapp->height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				win->mapp->exit += 1;
			if (map[i][j] == 'P')
				win->mapp->player += 1;
			if (map[i][j] == 'C')
				win->mapp->collect += 1;
			j++;
		}
		i++;
	}
	argv_control(win);
}
