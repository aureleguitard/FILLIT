/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:15:43 by auguitar          #+#    #+#             */
/*   Updated: 2019/06/29 15:15:47 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		piece_count(char *str)
{
	int pieces;

	pieces = 1;
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
			pieces++;
		str++;
	}
	return (pieces);
}

int		init_size(int pieces)
{
	int		i;
	int		min;

	i = 2;
	min = pieces * 4;
	while (min > (i * i))
		i++;
	return (i);
}

char	get_letter(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}

void	remove_char(char *str, char c)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
		{
			j = i;
			while (j < ft_strlen(str))
			{
				str[j] = str[j + 1];
				j++;
			}
		}
		i++;
	}
}
