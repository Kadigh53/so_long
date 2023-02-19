/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:43:20 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/19 16:16:28 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(int x)
{
	if (x == 0)
		write(2, "ERROR:invalid numbre of args\n./so_long map.ber",48);
	else if (x == 1)
		write(2, "ERROR:invalid map",18);
	else if (x == 2)
		write(2, "ERROR:invalid map the player couldnt finish the game",52);
	exit(1);
}

int main(int ac, char *av[])
{
	if (ac != 2)
		errors(0);
	if (!map_parsing(av[1]))
		errors(1);
	if (!backtrack(av))
		errors(2);
	drawing(av);
	// if(!drawing(av))
	// 	errors(0);
	return (0);
}
