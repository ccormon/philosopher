# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 14:31:43 by ccormon           #+#    #+#              #
#    Updated: 2024/05/15 16:21:14 by ccormon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers

CC		=	cc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=thread -g

SRC		=	main.c\
			utils.c\
			init.c\
			routine.c\
			routine_utils.c\

OBJ 	=	$(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clear clean fclean re
