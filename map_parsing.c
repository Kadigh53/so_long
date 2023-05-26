/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:49:08 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/26 10:51:04 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_eandp(char **map)
{
	int	i;
	int	j;
	int p;
	int e;

	i = -1;
	e = 0;
	p = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j++])
		{
			if (map[i][j - 1] == 'P')
				p++;
			else if (map[i][j - 1] == 'E')
				e++;
		}
	}
	if (e != 1 || p != 1)
		errors(1);
}

char	*borders_checking(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] == '1')
		i++;
	if (line[i] == '\n')
		i++;
	if (line[i] == '\0')
		return ((void *)1);
	return (NULL);
}

char	*lines_checking(char *line, int len)
{
	int			i;

	i = 0;
	if (line[i] == '1' && line[len - 2] == '1')
		i++;
	else if ((line[i] != '1' || line[len - 2] != '1') || len != ft_strlen(line))
		return (NULL);
	while (line[i] == '0' || line[i] == '1' || line[i] == 'C'
		|| line[i] == 'E' || line[i] == 'P' || line[i] == '\n')
	{
		i++;
	}
	if (!line[i])
		return ((void *)1);
	return (NULL);
}

char	*map_parsing(char *av)
{
	t_vars	vars;
	char	*line;

	vars.fd = open(av, O_RDONLY);
	if (vars.fd < 0)
		return (NULL);
	line = get_next_line(vars.fd);
	if (!borders_checking(line))
		return (NULL);
	vars.len = ft_strlen(line);
	while (1)
	{
		free(line);
		line = get_next_line(vars.fd);
		if (!line)
			break ;
		vars.buffer = line;
		if (!lines_checking(line, vars.len))
			return (NULL);
	}
	if (!borders_checking(vars.buffer))
		return (NULL);
	close(vars.fd);
	return ((void *)1);
}
