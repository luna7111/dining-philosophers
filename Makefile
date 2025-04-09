# **************************************************************************** #
#                                                                              #
#                                                     _.._  .           .      #
#    Makefile                                           :+:      :+:    :+:    #
#                                                  /  /       +        *       #
#    By: ldel-val <ldel-val@student.42madrid.com>  |  |           *            #
#                                                  \  '.___.;       +          #
#    Created: 2025/03/21 23:48:53 by ldel-val       '._  _.'   .        .      #
#    Updated: 2025/04/07 17:39:21 by ldel-val         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	cc

CFLAGS	:=	-Wall -Wextra -Werror -O3 -Isrc

RM		:=	rm -f

NAME	:=	philo

SRC		:=	src/philo.c\
			src/aux.c\
			src/routines.c\
			src/actions.c\
			src/fork_actions.c

OBJ		:=	$(SRC:.c=.o)

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re
