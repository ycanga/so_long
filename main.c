/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:01 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/10 11:19:12 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win	*win;

	if (ac == 2)
	{
		win = ft_calloc(sizeof(t_win), 1);
		win->mapp = ft_calloc(sizeof(t_map), 1);
		win->mlxx = ft_calloc(sizeof(t_mlx),1);
		ber_control(av[1]);
		win->mapp->map = &av[1];
		read_map(av[1], win);
		mlx_put_image(win);
	}
	else
		ft_printf("\033[31mArgument Error !!!");
}
