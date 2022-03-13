
NAME = so_long

ALL : ${NAME}

${NAME}: 
	gcc *.c  -lmlx -framework OpenGL -framework AppKit -o ${NAME}

exec:
	./so_long map.ber

clean:
	rm so_long

re: clean ALL exec