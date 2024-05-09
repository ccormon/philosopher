# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 15:48:31 by ccormon           #+#    #+#              #
#    Updated: 2024/05/09 16:28:33 by ccormon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror

NAME = libft.a

SRC =	ft_is/ft_isalnum.c\
		ft_is/ft_isalpha.c\
		ft_is/ft_isascii.c\
		ft_is/ft_isdigit.c\
		ft_is/ft_isprint.c\
		ft_is/ft_isspace.c\
		ft_is/ft_isnumber.c\
		ft_lst/ft_lstadd_back.c\
		ft_lst/ft_lstadd_front.c\
		ft_lst/ft_lstclear.c\
		ft_lst/ft_lstdelone.c\
		ft_lst/ft_lstiter.c\
		ft_lst/ft_lstlast.c\
		ft_lst/ft_lstmap.c\
		ft_lst/ft_lstnew.c\
		ft_lst/ft_lstsize.c\
		ft_mem/ft_memchr.c\
		ft_mem/ft_memcmp.c\
		ft_mem/ft_memcpy.c\
		ft_mem/ft_memmove.c\
		ft_mem/ft_memset.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_printf_utils1.c\
		ft_printf/ft_printf_utils2.c\
		ft_put_fd/ft_putchar_fd.c\
		ft_put_fd/ft_putendl_fd.c\
		ft_put_fd/ft_putnbr_fd.c\
		ft_put_fd/ft_putstr_fd.c\
		ft_str/ft_strcat.c\
		ft_str/ft_strchr.c\
		ft_str/ft_strdup.c\
		ft_str/ft_striteri.c\
		ft_str/ft_strjoin.c\
		ft_str/ft_strlcat.c\
		ft_str/ft_strlcpy.c\
		ft_str/ft_strlen.c\
		ft_str/ft_strmapi.c\
		ft_str/ft_strncmp.c\
		ft_str/ft_strnstr.c\
		ft_str/ft_strrchr.c\
		ft_str/ft_strtrim.c\
		ft_str/ft_split.c\
		ft_str/ft_substr.c\
		ft_str/ft_tolower.c\
		ft_str/ft_toupper.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		ft_alloc/ft_bzero.c\
		ft_alloc/ft_calloc.c\
		ft_to/ft_atoi.c\
		ft_to/ft_itoa.c\
		ft_to/ft_atol.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -o $@ -c $^

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
