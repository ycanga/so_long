/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:01 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/25 19:32:38 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		true;

	true = 0;
	if (ac == 2)
	{
		win = ft_calloc(sizeof(t_win), 1);
		win->mapp = ft_calloc(sizeof(t_map), 1);
		win->mapp->map = &av[1];
		read_map(av[1]);
		
	}
	else
		ft_printf("Argument Error !!!");

	// system("leaks so_long");
}