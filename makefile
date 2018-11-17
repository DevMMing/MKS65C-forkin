compile:  forkin.o
	gcc forkin.o
run:
	./a.out
clean:
	rm *.o ./a.out
forkin.o: forkin.c
	gcc -c forkin.c
