/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:14:32 by auguitar          #+#    #+#             */
/*   Updated: 2019/06/29 15:14:39 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char	**setup_grid(int size)
{
	char	**grid;
	int		i;
	int		j;
	int		over;

	i = 0;
	over = size + 3;
	if (!(grid = (char **)ft_memalloc(sizeof(char *) * (over + 1))))
		return (0);
	grid[over] = 0;
	while (i < size)
	{
		j = 0;
		if (!(grid[i] = (char *)ft_memalloc(over)))
			return (0);
		while (j < size)
			grid[i][j++] = '.';
		i++;
	}
	i--;
	while (++i < over)
		grid[i] = (char *)ft_memalloc(over);
	return (grid);
}

void	setup_letters(char **puzzle, int pieces)
{
	int	i;
	int j;

	i = 0;
	while (i < pieces)
	{
		j = 0;
		while (puzzle[i][j])
		{
			if (puzzle[i][j] == '\0')
				break ;
			if (puzzle[i][j] == '#')
				puzzle[i][j] = (65 + i);
			j++;
		}
		i++;
	}
}

int		setup(char **puzzle, int pieces)
{
	int i;

	i = -1;
	while (++i < pieces)
		remove_char(puzzle[i], '\n');
	if (!valid_pattern(puzzle, pieces))
		return (0);
	setup_letters(puzzle, pieces);
	solve(puzzle, pieces);
	return (0);
}

int		puzzle(char *str)
{
	int		pieces;
	char	**puzzle;
	int		i;
	int		j;

	i = 0;
	pieces = piece_count(str);
	if (pieces >= 27)
		error();
	if (!(puzzle = (char **)ft_memalloc(sizeof(char *) * (pieces + 1))))
		return (0);
	while (i < pieces)
	{
		j = 0;
		if (!(puzzle[i] = (char *)ft_memalloc(sizeof(char) * (20 + 1))))
			return (0);
		while (*str && !(*str == '\n' && *(str + 1) == '\n'))
			puzzle[i][j++] = *str++;
		puzzle[i++][j] = '\0';
		str += 2;
	}
	puzzle[pieces] = 0;
	setup(puzzle, pieces);
	return (0);
}
