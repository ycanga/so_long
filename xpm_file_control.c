/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:39:49 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/16 17:46:27 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xpm_control(void)
{
	int		fd_chr;
	int		fd_chr_r;
	int		fd_chr_l;
	int		fd_chr_b;

	fd_chr = open("./xpm/fire.xpm", O_RDONLY);
	fd_chr_r = open("./xpm/fire_r.xpm", O_RDONLY);
	fd_chr_l = open("./xpm/fire_l.xpm", O_RDONLY);
	fd_chr_b = open("./xpm/fire_b.xpm", O_RDONLY);
	if (fd_chr <= 0 || fd_chr_r <= 0 || fd_chr_l <= 0 || fd_chr_b <= 0)
		return (0);
	else
		return (1);
	close(fd_chr);
	close(fd_chr_r);
	close(fd_chr_l);
	close(fd_chr_b);
}

int	xpm_control_2(void)
{
	int		fd_ext;
	int		fd_wall;
	int		fd_bg;
	int		fd_coll;

	fd_ext = open("./xpm/exit.xpm", O_RDONLY);
	fd_wall = open("./xpm/wall.xpm", O_RDONLY);
	fd_bg = open("./xpm/bg.xpm", O_RDONLY);
	fd_coll = open("./xpm/heart.xpm", O_RDONLY);
	if (fd_ext <= 0 || fd_wall <= 0 || fd_bg <= 0 || fd_coll <= 0)
		return (0);
	else
		return (1);
	close(fd_ext);
	close(fd_wall);
	close(fd_bg);
	close(fd_coll);
}
