/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:53:19 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/16 21:56:56 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_digits(int n)
{
	int				i;
	unsigned int	k;

	i = 1;
	if (n < 0)
		k = n * (-1);
	else
		k = n;
	while (k >= 10)
	{
		i++;
		k = k / 10;
	}
	return (i);
}

static int	power(int b, int i)
{
	while (i)
	{
		b = b * 10;
		i--;
	}
	return (b);
}

static char	*add_nbrs(char *p, int n, int i, int j)
{
	while (i)
	{
		p[j] = (n / power(1, i - 1) + '0');
		n = n % power(1, i - 1);
		j++;
		i--;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*p;
	int		k;

	i = count_digits(n);
	j = 0;
	if (n < 0)
		k = i + 2;
	else
		k = i + 1;
	p = malloc((k) * sizeof(char));
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		n = n *(-1);
		j++;
	}
	add_nbrs(p, n, i, j);
	return (p);
}
