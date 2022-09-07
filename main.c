/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:01 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/07 20:09:12 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win	*win;
	void	*mlx;
	void	*mlx_win;
	void 	*ates;
	void	*su;
	void	*heart;
	void	*wall;
	void	*bg;
	int		x, y; 

	if (ac == 2)
	{
		
		win = ft_calloc(sizeof(t_win), 1);
		win->mapp = ft_calloc(sizeof(t_map), 1);
		ber_control(av[1]);
		win->mapp->map = &av[1];
		read_map(av[1], win);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "Ateş ve Su");
 		ates = mlx_xpm_file_to_image(mlx, "./xpm/ates.xpm", &x, &y);
		su = mlx_xpm_file_to_image(mlx, "./xpm/su.xpm", &x, &y);
		heart = mlx_xpm_file_to_image(mlx, "./xpm/heart.xpm", &x, &y);
		wall = mlx_xpm_file_to_image(mlx, "./xpm/wall.xpm", &x, &y);
		bg = mlx_xpm_file_to_image(mlx, "./xpm/bg.xpm", &x, &y); 
		mlx_put_image_to_window(mlx, mlx_win, ates, 50, 50);
		mlx_put_image_to_window(mlx, mlx_win, su, 100, 100);
		mlx_put_image_to_window(mlx, mlx_win, heart, 150, 150);
		mlx_put_image_to_window(mlx, mlx_win, wall, 200, 200);
		mlx_put_image_to_window(mlx, mlx_win, bg, 300, 300); 
		mlx_loop(mlx);
	}
	else
		ft_printf("Argument Error !!!");
}
