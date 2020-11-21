c:
	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g -Wall -Wextra -pedantic -std=c99
r:
	bin/main
cr:
	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g -Wall -Wextra -pedantic -std=c99
	bin/main
rd:
	gdb bin/main
crd:
	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g -Wall -Wextra -pedantic -std=c99
	gdb bin/main
