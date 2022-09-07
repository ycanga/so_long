/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:30:03 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/07 12:56:52 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	argv_true(t_win *win, int i, int j)
{
	if (win->mapp->map[i - 1][j] == '1' && win->mapp->map[i + 1][j] == '1' \
	&& win->mapp->map[i][j + 1] == '1' && win->mapp->map[i][j - 1] == '1')
	{
		win->mapp->map_true = 0;
		ft_error(win, 0);
	}
	else
		win->mapp->map_true = 1;
}

void	map_valid_control(t_win *win)
{
	int		i;
	int		j;
	char	**map;

	map = win->mapp->map;
	i = 0;
	while (i < win->mapp->height)
	{
		j = 0;
		while (j <= win->mapp->width - 1)
		{
			if (map[i][j] == 'E')
				argv_true(win, i, j);
			else if (map[i][j] == 'P')
				argv_true(win, i, j);
			else if (map[i][j] == 'C')
				argv_true(win, i, j);
			j++;
		}
		i++;
	}
}

void	argv_control(t_win *win)
{
	if (win->mapp->player != 1)
		ft_error(win, 2);
	if (win->mapp->exit != 1)
		ft_error(win, 2);
	if (win->mapp->collect < 0)
		ft_error(win, 2);
	map_valid_control(win);
}
