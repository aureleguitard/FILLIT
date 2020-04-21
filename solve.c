/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:15:05 by auguitar          #+#    #+#             */
/*   Updated: 2019/06/29 15:15:10 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	print_grid(char **grid, int pieces)
{
	int	i;

	i = 0;
	while (i < pieces)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

int		solve(char **puzzle, int pieces)
{
	char	**grid;
	int		grid_size;

	grid_size = init_size(pieces);
	grid = setup_grid(grid_size);
	if (!grid)
		return (0);
	while (!(recursion(grid, puzzle, 0, 0)))
	{
		grid_size++;
		grid = setup_grid(grid_size);
		if (!grid)
			return (0);
	}
	print_grid(grid, grid_size);
	return (1);
}
