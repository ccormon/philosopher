# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 14:31:43 by ccormon           #+#    #+#              #
#    Updated: 2024/05/09 14:47:21 by ccormon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philosophers

CC 			= cc
RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror -fsanitize=thread -g
CLINKS		= -lreadline

LIBFTDIR	= libft
LIBFT		= $(LIBFTDIR)/libft.a

SRC		=	main.c\

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(CLINKS)

$(LIBFT):
	$(MAKE) -C $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clear clean fclean re
