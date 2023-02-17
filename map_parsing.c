/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:49:08 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/17 15:10:12 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char	*borders_checking(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] == '1')
		i++;
	if (line[i + 1] == '\0')
		return ((void *)1);
	return (NULL);
}

char	*lines_checking(char *line, int len)
{
	static int	ep;
	static int	c;
	int			i;

	i = 0;
	if (line[i] == '1' && line[len - 2] == '1')
		i++;
	else if ((line[i] != '1' || line[len - 2] != '1') || len != ft_strlen(line))
		return (NULL);
	while (line[i] == '0' || line[i] == '1' || line[i] == 'C'
		|| line[i] == 'E' || line[i] == 'P' || line[i] == '\n')
	{
		if (line[i] == 69)
			ep++;
		if (line[i] == 80)
			ep++;
		if (line[i] == 'C')
			c++;
		i++;
	}
	if ((!line[i] && ep <= 2) && c > 0)
		return ((void *)1);
	return (NULL);
}

char	*map_parsing(char *av)
{
	int			fd;
	int			len;
	char		*line;
	char		*buffer;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!borders_checking(line))
		return (NULL);
	len = ft_strlen(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		buffer = line; // free(line);
		if (!lines_checking(line, len))
			return (NULL);
	}
	if (!borders_checking(buffer))
		return (NULL);
	close(fd);
	return ((void *)1);
}
