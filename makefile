TARGET=t.out

all:
	gcc -lreadline shell.c -o $(TARGET)
clean:
	rm $(TARGET)

