SRC			= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

CC			= g++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME		= materia

all:	${NAME}

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all