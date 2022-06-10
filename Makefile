# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 11:15:29 by marmoral          #+#    #+#              #
#    Updated: 2022/06/10 13:36:53 by marmoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

LPATH = ./libft

FILES =	ft_printf.c ft_put_hexa_low.c ft_put_hexa_up.c ft_put_u.c ft_put_c.c ft_put_id.c ft_put_s.c\

OBJ = ${FILES:.c=.o}

all:$(NAME)

$(NAME): ${OBJ}
	make re -C $(LPATH)
	ar rcs $(NAME) $(OBJ) $(LPATH)/ft_*.o

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean:
	rm -f $(OBJ)
	make clean -C $(LPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LPATH)

re: fclean all

.PHONY:        all clean fclean re