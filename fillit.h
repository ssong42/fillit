/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:04:25 by ttran             #+#    #+#             */
/*   Updated: 2018/03/21 09:37:56 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

extern int			g_size;
extern int			g_gc;
void				ft_putstr(char *str);
void				ft_putchar(char c);
typedef struct		s_tetri
{
	char			**tetrimino;
	struct s_tetri	*next;
	int				flag;
	int				minx;
	int				miny;
	int				maxx;
	int				maxy;
	int				fx;
	int				fy;
	char			letter;
}					t_tetri;
typedef struct		s_savespace
{
	int		br;
	int		f;
	int		fd;
	char	str[21];
}					t_savespace;
void				setparse(t_tetri **p, t_tetri *list, t_savespace *s);
int					ft_listcreate(t_tetri **p, char *str, int br);
char				**ft_convertdata(char *str, int br, t_tetri *fuck);
t_tetri				*parsefile(char *file);
void				ft_free(t_tetri *tetri);
int					open_error(int fd);
int					close_err(int fd);
int					ft_check_buffer(char *str, int br);
int					ft_check_characters(char *str);
int					ft_check_connections(char **str, int y, int x);
void				ft_min(t_tetri *fuck, int y, int x, int pound);
void				ft_max(t_tetri *fuck, int y, int x, int pound);
int					check_valid(t_tetri *fuck, char **store);
int					ft_setletter(t_tetri *fuck);
char				**find_grid(t_tetri *tetri);
void				print_grid(char **grid);
int					more_tetri(t_tetri *tetri);
void				re_zero(t_tetri *tetri);
void				set_flags(t_tetri *tetri);
int					find_locat(char **grid, int *x, int *y);
char				**malloc_grid(int size);
#endif
