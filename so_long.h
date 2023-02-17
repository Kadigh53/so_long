/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:00:33 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/17 17:54:27 by aaoutem-         ###   ########.fr       */
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

typedef struct data 
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
	int		Le;
	int		cor[2];
	int		Count;
	int		move_count;
} t_data;

char	*map_parsing(char *av);

void	drawing(char *av[]);
void    render(t_data **data);

void	move_left(t_data **data);
void	move_right(t_data **data);
void	move_down(t_data **data);
void	move_up(t_data **data);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
int		C_nbr(char *map[]);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);




// char	*ft_substr(char *s, unsigned int start, size_t len);
// char	*ft_strjoin(char *s1, char *s2);

#endif