NAME = 		lab_4

CLINET = 	client.c
SERVER = 	server.c
HEADER = 	lab4.h

OBJS = ${patsubst %.c, %.o, ${SRCS}}
CLINET_OBJ = ${patsubst %.c, %.o, ${CLINET}}
SERVER_OBJ = ${patsubst %.c, %.o, ${SERVER}}

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: client server


client: ${CLINET_OBJ} ${OBJS}
	gcc ${CLINET_OBJ} ${OBJS} -o $@ -I ${HEADER}

server: ${SERVER_OBJ} ${OBJS}
	gcc ${SERVER_OBJ} ${OBJS} -o $@ -I ${HEADER}

%.o: %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

clean:
	rm -f *.o *.g.gch

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re