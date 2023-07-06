# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:37:51 by aaslan            #+#    #+#              #
#    Updated: 2023/06/20 02:48:56 by aaslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -lreadline -g
SRC			:= $(wildcard src/*.c)
OTHERS_SRC	:= $(wildcard src/*/*.c)
OBJS		:= $(SRC:%.c=%.o)
OTHERS_OBJS	:= $(OTHERS_SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS) $(OTHERS_OBJS)
	@$(CC) $(OBJS) $(OTHERS_OBJS) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OTHERS_OBJS)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@clear

re: fclean all

norm:
	@norminette *.h *.c

.PHONY: all clean fclean re
