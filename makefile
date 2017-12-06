all: semaphore.c
	gcc -o control semaphore.c
run: all
	./control -c 4
	./control -c 3
	./control -v
	./control -r
