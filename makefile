c:
	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g
r:
	bin/main
cr:
	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g
	bin/main
rd:
	gdb bin/main
crd:
	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g
	gdb bin/main
