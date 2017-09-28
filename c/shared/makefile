all: main

main: main.o libShared.so
	gcc -L/home/jarhar/foo/c/shared $< -o $@ -lShared

main.o: main.c
	gcc -c $< -o $@

libShared.o: libShared.c
	gcc -fpic -c $< -o $@

libShared.so: libShared.o
	gcc -shared $< -o $@

clean:
	-rm -rf libShared.so libShared.o main.o main
