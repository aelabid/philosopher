# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 16:12:20 by aelabid           #+#    #+#              #
#    Updated: 2022/04/01 20:32:49 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =  initialise.c philosophers_utile.c philosophers.c atoi.c threads.c \
		forks.c gettime.c routine.c destroy.c

OBJ = $(SRC:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror
CC = gcc


NAME = philosophers
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS)  $(OBJ) -o $@
	
%.o: %.c philosophers.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all
