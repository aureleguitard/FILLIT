/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:55:50 by auguitar          #+#    #+#             */
/*   Updated: 2019/06/29 15:12:40 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check_backs(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i - 1] != '.' && str[i - 1] != '#')
		return (0);
	return (1);
}
