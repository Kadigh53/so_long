/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:00:33 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/10 18:59:08 by aaoutem-         ###   ########.fr       */
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

char	*map_parsing(char *av);
void	drawing(char *av[]);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
// char	*ft_substr(char *s, unsigned int start, size_t len);
// char	*ft_strjoin(char *s1, char *s2);

#endif