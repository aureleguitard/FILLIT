# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguitar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 15:16:39 by auguitar          #+#    #+#              #
#    Updated: 2019/06/29 17:20:39 by auguitar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FTS = fillit utils check_input solve setup recursion pattern check_backslash

CFLAGS = -Wall -Wextra -Werror

LDF = -L libft/ -lft

SRC = $(addsuffix .c, $(FTS))

OBJS = $(addsuffix .o, $(FTS))

all: $(NAME)

$(NAME):
	@make -C libft/ all
	@gcc $(CFLAGS) $(LDF) $(SRC) -I includes -I libft/ -o $(NAME)

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
