# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:06:20 by gd-auria          #+#    #+#              #
#    Updated: 2024/03/20 15:10:43 by gd-auria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c exec_path.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		make -C libft/
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME) libft/libft.a

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		make fclean -C libft

fclean: clean
		$(RM) $(NAME)
		make fclean -C libft

re: 	fclean all
