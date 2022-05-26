# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 22:07:12 by marmoral          #+#    #+#              #
#    Updated: 2022/05/17 10:27:25 by marmoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

CFLAGS =	-Wall -Wextra -Werror

FILES =	ft_tolower.c ft_toupper.c ft_isalpha.c ft_isalnum.c ft_isdigit.c\
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_memset.c ft_bzero.c\
	ft_strncmp.c ft_memcpy.c ft_putchar_fd.c ft_memmove.c ft_memcpy.c\
	ft_strchr.c	ft_strrchr.c ft_calloc.c ft_strdup.c\
	ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_memchr.c\
	ft_memcmp.c ft_isascii.c ft_isprint.c ft_putendl_fd.c ft_putstr_fd.c\
	ft_strmapi.c ft_strnstr.c ft_itoa.c ft_split.c\

OBJS = ${FILES:.c=.o}

RM = rm -f

CC = gcc

all: $(NAME)


$(NAME) : ${OBJS}
	ar rcs $(NAME) ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME) 

re: clean all