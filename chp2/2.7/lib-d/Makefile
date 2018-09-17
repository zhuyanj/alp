all:
	gcc -c -fPIC test.c
	gcc -shared -fPIC -o libtest.so test.o
	gcc -o app app.c -L. -ltest
