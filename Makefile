all:shader_load.o Utils.o main.cpp 
	g++ -o main main.cpp shader_load.o Utils.o -lglut -lGLU -lGL -lGLEW -lm -pthread

shader_load.o: shader_load.cpp shader_load.h
	g++ -c shader_load.cpp -o shader_load.o  -lglut -lGLU -lGL -lGLEW -lm -pthread

Utils.o: Utils.cpp Utils.h
	g++ -c 	Utils.cpp -o Utils.o

clean:
	rm -rf shader.o Utils.o main main.o shader_load.o
