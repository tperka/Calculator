
CC := gcc
CFLAGS := -c -Wall -pedantic
INC := -I include

runner.o: main.o Arrays_management.o Operations.o Interface.o
	gcc build/main.o build/Arrays_management.o build/Operations.o build/Interface.o -o bin/runner.o

main.o:
	mkdir -p build bin
	$(CC) src/main.c $(CFLAGS) $(INC) -o build/main.o

Arrays_management.o:
	$(CC) src/Arrays_management.c $(CFLAGS) $(INC) -o build/Arrays_management.o

Operations.o:
	$(CC) src/Operations.c $(CFLAGS) $(INC) -o build/Operations.o

Interface.o:
	$(CC) src/Interface.c $(CFLAGS) $(INC) -o build/Interface.o

clean:
	rm -rf build bin
