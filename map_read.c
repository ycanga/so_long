/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:34:00 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/25 19:51:50 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	control_argv()
{
	ft_printf("%s", win->mapp->map[0]);
}
void	read_map(char *maps)
{
	int		fd;
	char	*line;
	int		count;
	int		i;
	
	if (maps)
	{
		i = 0;
		count = 0;
		fd = open(maps, O_RDONLY);
		if (fd < 0)
			ft_printf("Invalid map");
		line = get_next_line(fd);
		if (line == 0)
			ft_printf("Invalid map size");
		win->mapp->width = ft_strlen(line)-1;
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
		// ft_printf("%d\n", win->mapp->width);
		// ft_printf("%d", win->mapp->height);
		free(line);
		close(fd);
	}
	else
		ft_printf("Error Maps");	
}