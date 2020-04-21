/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:17:48 by auguitar          #+#    #+#             */
/*   Updated: 2019/06/29 15:18:42 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 1024

void	ft_read_file(int fd, char *str);
int		error(void);
int		check_form(char *str);
int		check_line(char *str);
int		check_char(char *str);
int		check_hash(char *str, int line, int i);
int		check_tetrimino(char *str);
int		puzzle(char *str);
int		piece_count(char *str);
int		check_all(char *str);
char	**setup_grid(int over);
void	setup_letters(char **puzzle, int pieces);
int		init_size(int pieces);
int		setup(char **puzzle, int pieces);
int		solve(char **puzzle, int pieces);
int		recursion(char **grid, char **puzzle, int row, int col);
int		check_place(char **grid, char *tetri, int row, int col);
void	place_tetri(char **grid, char *tetri, int row, int col);
void	remove_tetri(char **grid, char *tetri, int row, int col);
char	get_letter(char *str);
int		is_valid(char *src, char *pat);
void	get_valid(char valid[20][14], int i);
int		valid_pattern(char **src, int pieces);
void	print_grid(char **grid, int num);
void	remove_char(char *str, char c);
int		check_backs(char *str);

#endif
