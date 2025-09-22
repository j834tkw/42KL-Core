SRC			= main.cpp Fixed.cpp

CC			= g++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= fixed

all:	${NAME}

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all