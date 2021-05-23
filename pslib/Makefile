# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 16:16:23 by mvaldeta          #+#    #+#              #
#    Updated: 2021/05/23 20:41:40 by mvaldeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PSLIB: Library for pushswap project.
# (｡◕‿◕｡)

SRC 		= $(wildcard *.c)

OBJ 		= $(SRC:.c=.o)

INC 		= includes

NAME 		= pslib.a

CC			= gcc

ARRC		= ar rcs

RM			= rm -f

#CFLAGS		= -Wall -Wextra -Werror 

.c.o: 
			${CC} -g ${CFLAGS} -c $^ -o ${<:.c=.o} -I${INC}

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
		$(NAME)
		
.PHONY: all clean fclean re
