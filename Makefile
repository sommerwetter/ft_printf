# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 11:15:29 by marmoral          #+#    #+#              #
#    Updated: 2022/07/11 01:37:14 by marmoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

LPATH = ./libft

FILES =	ft_printf.c ft_put_hexa_low.c ft_put_hexa_up.c ft_put_u.c\

OBJ = ${FILES:.c=.o}

RM = rm -f

all:$(NAME)

$(NAME): ${OBJ}
	make re -C $(LPATH)
	ar rcs $(NAME) $(OBJ) $(LPATH)/ft_*.o

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^ 

clean:
	$(RM) $(OBJ)
	make clean -C $(LPATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LPATH)

re: fclean all

.PHONY:        all clean fclean re