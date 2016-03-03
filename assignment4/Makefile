CXX = g++ -std=c++11 -Wall -g

%.o : %.c 
	$(CXX) -c $< 

testMaze: utils.o testMaze.o maze.o
	$(CXX) -o $@ testMaze.o utils.o maze.o

main: utils.o main.o maze.o
	$(CXX) -o $@ main.o utils.o maze.o

clean:
	$(RM) main testMaze *.o
