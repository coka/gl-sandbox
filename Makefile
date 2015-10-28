all: sandbox

sandbox: main.o
	c++ -framework OpenGL -lglfw main.o -o sandbox

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm sandbox main.o
