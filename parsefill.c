/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:08:36 by ttran             #+#    #+#             */
/*   Updated: 2018/03/21 09:38:30 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_listcreate(t_tetri **p, char *str, int g_br)
{
	t_tetri	*new;

	new = malloc(sizeof(t_tetri));
	new->next = 0;
	new->tetrimino = ft_convertdata(str, g_br, new);
	if (!(new->tetrimino))
		return (0);
	(*p)->next = new;
	(*p) = new;
	return (1);
}

char	**ft_convertdata(char *str, int g_br, t_tetri *fuck)
{
	int		i;
	char	**store;
	int		n;

	if (ft_check_buffer(str, g_br) == 0)
		return (NULL);
	n = 0;
	store = (char **)malloc(sizeof(char *) * 5);
	while (n < 4)
		store[n++] = (char *)malloc(sizeof(char) * 5);
	store[4] = 0;
	n = 0;
	str[20] = '\0';
	while (*str)
	{
		i = 0;
		while (*str != '\n' && *str != '\0')
			store[n][i++] = *str++;
		store[n++][i] = '\0';
		str++;
	}
	if (check_valid(fuck, store) == 0)
		return (NULL);
	return (store);
}

void	setparse(t_tetri **p, t_tetri *list, t_savespace *s)
{
	list->tetrimino = NULL;
	list->next = NULL;
	*p = list;
	s->f = 0;
}

t_tetri	*parsefile(char *file)
{
	t_savespace *s;
	t_tetri		*list;
	t_tetri		*p;

	s = malloc(sizeof(t_savespace));
	s->fd = open(file, O_RDONLY);
	if (open_error(s->fd) == 0)
		return (NULL);
	list = malloc(sizeof(t_tetri));
	setparse(&p, list, s);
	while ((s->br = read(s->fd, s->str, 21)) >= 20)
	{
		if (s->br == 20)
			s->f = 1;
		if (list->tetrimino == NULL)
		{
			if (!(list->tetrimino = ft_convertdata(s->str, s->br, list)))
				return (NULL);
		}
		else if (ft_listcreate(&p, s->str, s->br) == 0)
			return (NULL);
	}
	if ((close_err(close(s->fd)) == 0) || s->br != 0 || g_gc == 0 || s->f == 0)
		return (NULL);
	return (list);
}

void	ft_free(t_tetri *tetri)
{
	t_tetri	*p;

	while (tetri != NULL)
	{
		p = tetri;
		tetri = tetri->next;
		p->tetrimino = 0;
		p->next = NULL;
		free(p);
	}
}
