/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:10:38 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/30 09:57:53 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	map_contents(char **map_char)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (map_char[i][j])
// 	{
// 		if (map_char[i][j] == 'E')
// 			win->mapp->exit +=1;
// 		if (map_char[i][j] == 'P')
// 			win->mapp->exit +=1;
// 		if (map_char[i][j] == 'C')
// 			win->mapp->exit +=1;
// 		if (map_char[i][j] == 'E')
// 			win->mapp->exit +=1;
// 		if (map_char[i][j] == 'E')
// 			win->mapp->exit +=1;
// 	}
	
// }

// void	map_argv_control(void)
// {
// 	int		i;
// 	int		j;
// 	int		last_char;
// 	int		map_height;
// 	char	**map_char;

// 	i = 1;
// 	j = 1;
// 	map_height = win->mapp->height;
// 	last_char = win->mapp->width - 1;
// 	map_char = win->mapp->map;
// 	ft_printf("%d\n", map_height);
// 	ft_printf("%d\n", last_char);
// 	while (i < map_height)
// 	{
// 		while (map_char[i][j])
// 		{
// 			if (map_char[i][j] && j != last_char - 1)
// 				map_contents(map_char);
// 			else
// 				ft_printf("Error !!!");
// 			j++;
// 		}
// 		i++;
// 	}
// } 

// void	map_lenght(char **map_char)
// {
	
// }

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
	// int i = 0;
	// while (map_char[i])
	// {
	// 	ft_printf("%s\n", map_char[i]);
	// 	i++;
	// }
	
	// map_lenght(map_char);
	
	// map_argv_control();
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
	win->mapp->width = ft_strlen(line) - 1;
	count = 0;
	while (line)
	{
		// ft_printf("%d\n", (int)ft_strlen(&line[i]));
		// ft_printf("%s", &line[i]);
		// ft_printf("%d\n", win->mapp->width);
		win->mapp->map[i] = ft_calloc(win->mapp->width, 1);
		ft_strlcpy(win->mapp->map[i], line, (int)ft_strlen(line) + 1);
		ft_printf("%s\n", win->mapp->map[i]) ;
		ft_printf("%d\n", (int)ft_strlen(win->mapp->map[i]) - 1);
		if ((int)ft_strlen(win->mapp->map[i] ) - 1 != win->mapp->width)
		{
			ft_printf("satır kısa\n");
			break;
		}
		
		free(line);
		line = get_next_line(fd);
		count++;
		i++;
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
	if(win->mapp->map_true == 1)
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
