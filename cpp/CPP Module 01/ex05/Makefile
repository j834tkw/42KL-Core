SRC			= main.cpp Harl.cpp

CC			= g++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= harl

all:	${NAME}

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all