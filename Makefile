
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 22:30:51 by chideyuk          #+#    #+#              #
#    Updated: 2021/11/25 22:57:41 by chideyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	clean fclean re all

NAME	:= pipex
CFLAGS	:= -Wall -Wextra -Werror -o
CC	:= gcc
SRCS	:= utils/ft_bzero.c \
		utils/ft_error.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/ft_strncmp.c \
		utils/ft_strchr.c \
		ft_pathfinder.c \
		pipex.c

all	: $(NAME)

$(NAME)	: $(SRCS)
	$(CC) $(CFLAGS) $(NAME) $(SRCS)

clean	:

fclean	: clean
	rm -f $(NAME)

re	: fclean all