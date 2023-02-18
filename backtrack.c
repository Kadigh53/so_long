/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:22:17 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/18 21:02:05 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_instr(char *av[])
{
	char	*line;
	char	*map0;
	int		fd;

	fd = open(av[1],O_RDONLY);
	map0=NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map0 = ft_strjoin(map0, line);
		free(line);
	}
	close(fd);
	return (ft_split(map0,'\n'));
}

void	flood_fill(char   ***map, int y, int x)
{
	if ((*map)[y][x] == '1' || (*map)[y][x] == 'X')
		return ;
	(*map)[y][x] = 'X';
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
}

void    backtrack(char  **av, t_data **data)
{
	char **map;
	int i;
	int j;

	i = 0;
	map = map_instr(av);
	flood_fill(&map, (*data)->cor[0], (*data)->cor[0]);
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				//free(map);	
				return (NULL);
			}
			j++;
		}
		i++;
	}
	// free(map);
	return ((void *)1);
}


// void    backtrack(char  **av)//, t_data **data)
// {
// 	char **map;
// 	map = map_instr(av);
// 	flood_fill(&map, 4, 13);
// 	printf("{{%s}\n {%s}\n {%s}\n {%s}\n {%s}\n {%s}}\n\n",(map)[0],(map)[1],(map)[2],(map)[3],(map)[4],(map)[5]);
// }
// 	int i,j;
// 	i =0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while(map[i][j])
// 		{
// 			if (map[i][j] == 'C' || map[i][j] == 'E')
// 				printf("(%d,%d)NULL\n",j,i);
// 			j++;
// 		}
// 		i++;
// 	}
// }
// int main(int ac , char **av){
// 	backtrack(av);
// }