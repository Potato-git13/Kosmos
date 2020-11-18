c:
	gcc -o main src/main.c src/help.c src/access.c -lm -g
r:
	./main
cr:
	gcc -o main src/main.c src/help.c src/access.c -lm -g
	./main
rd:
	gdb ./main
crd:
	gcc -o main src/main.c src/help.c src/access.c -lm -g
	gdb ./main
