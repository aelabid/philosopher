# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 20:08:39 by aelabid           #+#    #+#              #
#    Updated: 2022/03/27 18:39:31 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = parsing.c atoi.c creat_philosophers.c

OBJ = $(SRC:.c=.o)

# CC_FLAGS = -Wall -Wextra -Werror
CC = gcc


NAME = philosophers
all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) -o $@
	
%.o: %.c philosopher.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all
