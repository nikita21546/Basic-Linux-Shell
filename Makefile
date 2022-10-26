TARGET= a.out

all: 
	gcc -lreadline final.c -o $(TARGET)

clean: 
	rm $(TARGET)
