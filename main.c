/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:42:49 by ttran             #+#    #+#             */
/*   Updated: 2018/03/21 09:38:59 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_size = 2;

int	main(int argc, char **argv)
{
	t_tetri	*tetri;
	char	**grid;

	grid = NULL;
	if (argc == 2)
	{
		if (!(tetri = parsefile(argv[1])))
		{
			ft_putstr("error\n");
			return (0);
		}
		grid = find_grid(tetri);
		print_grid(grid);
		ft_free(tetri);
	}
	else
	{
		ft_putstr("Usage:./fillit file");
		return (0);
	}
	return (1);
}
