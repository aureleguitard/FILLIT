/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:13:42 by auguitar          #+#    #+#             */
/*   Updated: 2019/06/29 15:13:48 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	place_tetri(char **grid, char *tetri, int row, int col)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (tetri[i])
	{
		if (tetri[i] != '.')
			grid[row][col] = tetri[i];
		i++;
		col++;
		n++;
		if (n == 4)
		{
			row++;
			col = col - 4;
			n = 0;
		}
	}
}

void	remove_tetri(char **grid, char *tetri, int row, int col)
{
	char	ch;
	int		i;

	ch = get_letter(tetri);
	i = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (i == 4)
				return ;
			if (grid[row][col] == ch)
			{
				i++;
				grid[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

int		check_place(char **grid, char *tetri, int row, int col)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (tetri[i])
	{
		if (n == 4)
		{
			row++;
			n = 0;
			col = col - 4;
		}
		if (tetri[i] >= 'A' && tetri[i] <= 'Z' && grid[row][col] != '.')
			return (0);
		n++;
		col++;
		i++;
	}
	return (1);
}

int		recursion(char **grid, char **puzzle, int row, int col)
{
	if (*puzzle == 0)
		return (1);
	while (grid[row])
	{
		while (grid[row][col])
		{
			if (check_place(grid, *puzzle, row, col))
			{
				place_tetri(grid, *puzzle, row, col);
				if (recursion(grid, (puzzle + 1), 0, 0))
					return (1);
				else
					remove_tetri(grid, *puzzle, row, col);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (0);
}
