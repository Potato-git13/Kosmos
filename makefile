c:
	if test -d bin; \
	then echo; \
	else mkdir bin; \
	fi

	if test -f src/pass; \
	then echo; \
	else touch src/pass; \
	echo "Password" >> src/pass; \
	fi
	
	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g -Wall -Wextra -pedantic -std=c99 -Wformat=2
r:
	if test -f src/pass; \
	then echo; \
	else echo; \
		if test -d src;\
		then echo; \
		else mkdir src; \
		fi; \
	touch src/pass; \
	echo "Password" >> src/pass; \
	fi

	bin/main
cr:
	if test -d bin; \
	then echo; \
	else mkdir bin; \
	fi

	if test -f src/pass; \
	then echo; \
	else touch src/pass; \
	echo "Password" >> src/pass; \
	fi

	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g -Wall -Wextra -pedantic -std=c99 -Wformat=2
	bin/main
rd:
	if test -f src/pass; \
	then echo; \
	else echo; \
		if test -d src;\
		then echo; \
		else mkdir src; \
		fi; \
	touch src/pass; \
	echo "Password" >> src/pass; \
	fi

	gdb bin/main
crd:
	if test -d bin; \
	then echo; \
	else mkdir bin; \
	fi

	if test -f src/pass; \
	then echo; \
	else touch src/pass; \
	echo "Password" >> src/pass; \
	fi

	gcc -o bin/main src/main.c src/help.c src/access.c -lm -g -Wall -Wextra -pedantic -std=c99 -Wformat=2
	gdb bin/main
