/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:17:41 by ssong             #+#    #+#             */
/*   Updated: 2017/12/21 22:54:12 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_reference(t_tetri *tmp, int tmpy, int tmpx)
{
	tmp->fy = tmpy;
	tmp->fx = tmpx;
	if (tmp->flag == 0)
		tmp->flag = 1;
	else if (tmp->flag == 1)
		tmp->flag = 0;
}

int		check_location(t_tetri *t, char **grid, int x, int y)
{
	int	tmpx;
	int tmpy;

	tmpy = -1;
	while (t->miny + ++tmpy <= t->maxy)
	{
		tmpx = -1;
		while (t->minx + ++tmpx <= t->maxx)
		{
			if (t->tetrimino[t->miny + tmpy][t->minx + tmpx] == '#')
			{
				if (t->flag == 0)
					set_reference(t, tmpy, tmpx);
				if (!(y + (tmpy - t->fy) < g_size
					&& x + (tmpx - t->fx) < g_size)
					|| !(y + (tmpy - t->fy) > -1 && x + (tmpx - t->fx) > -1)
					|| !(grid[y + (tmpy - t->fy)][x + (tmpx - t->fx)] == '.'))
					return (0);
				grid[y + (tmpy - t->fy)][x + (tmpx - t->fx)] = t->letter;
			}
		}
	}
	return (1);
}

/*
** Once an empty spot on the grid has been identified, this
** function will attempt to insert the current tetrimino
** into that location. Any times this will fail is when the
** tetrimino goes outside the boundaries or lands on
** another tetrimino.
*/

void	clean_grid(t_tetri *tmp, char **grid, int x, int y)
{
	int	tmpx;
	int tmpy;

	tmpy = 0;
	while (tmp->miny + tmpy <= tmp->maxy)
	{
		tmpx = 0;
		while (tmp->minx + tmpx <= tmp->maxx)
		{
			if (tmp->tetrimino[tmp->miny + tmpy][tmp->minx + tmpx] == '#')
			{
				if (tmp->flag == 1)
					set_reference(tmp, tmpy, tmpx);
				if ((y + (tmpy - tmp->fy) < g_size)
					&& (x + (tmpx - tmp->fx) < g_size))
					if (grid[y + (tmpy - tmp->fy)]
						[x + (tmpx - tmp->fx)] == tmp->letter)
						grid[y + (tmpy - tmp->fy)][x + (tmpx - tmp->fx)] = '.';
			}
			tmpx++;
		}
		tmpy++;
	}
}

/*
** Will reset the grid when the recursive part fails. This will allow for
** backtracking and reuse of the grid
*/

int		organize_tetrim(t_tetri *tetri, char **grid)
{
	t_tetri	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tmp = tetri;
	if (more_tetri(tmp) != 0)
		return (1);
	while (tmp != NULL)
	{
		if (tmp->flag == 0)
		{
			while (find_locat(grid, &x, &y) != 0)
			{
				if (check_location(tmp, grid, x, y) == 1)
					if (organize_tetrim(tetri, grid) == 1)
						return (1);
				clean_grid(tmp, grid, x, y);
				x++;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
** Will recursively attempt to fit all tetriminos in all possible
** locations until there are no more possible spots
** If it doesnt find a tetrimino capable of fitting into the
** grid then it will insert and pass the (grid, tetri)
** into the same function.
*/

char	**find_grid(t_tetri *tetri)
{
	char **grid;

	set_flags(tetri);
	while ((g_size * g_size) < ((g_gc) * 4))
		g_size++;
	grid = malloc_grid(g_size);
	while (organize_tetrim(tetri, grid) != 1)
	{
		re_zero(tetri);
		g_size++;
		grid = malloc_grid(g_size);
	}
	return (grid);
}

/*
** Will perform all the necessary functions to find the
** smallest grid with all the tetriminos inside. SUCCESS>>
*/
