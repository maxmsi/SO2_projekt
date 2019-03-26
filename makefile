all: 
	g++ -o projekt1 main.cpp  Balls.cpp Ball.cpp  Window.cpp Balls.h Ball.h Window.h -lncurses -fpermissive -pthread -std=c++11 


