/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:00:33 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/26 10:46:20 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_data		t_data ;
typedef struct s_pars_vars	t_vars;

struct s_data 
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	int		img_width;
	int		img_height;
	char	**map;
	int		x;
	int		y;
	int		l;
	int		le;
	int		cor[2];
	int		count;
	int		move_count;
};

struct s_pars_vars
{
	int			fd;
	int			len;
	char		*buffer;
};

char	*map_parsing(char *av);
void	drawing(char *av[]);
void	render(t_data **data);
void	errors(int x);
char	*backtrack(char **av);
void	move_left(t_data **data);
void	move_right(t_data **data);
void	move_down(t_data **data);
void	move_up(t_data **data);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
int		c_nbr(char *map[]);
void	ft_putnbr_fd(int n, int fd);
void	free_map(char	**map);
void	count_eandp(char **map);

#endif