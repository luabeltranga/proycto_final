CC=g++
FLAGS= -std=c++11 -fsanitize=address -fsanitize=leak -fsanitize=undefined 
#FLAGS= -std=c++11 -ggdb -g
vot1d: votaciones1d.cpp
	$(CC) $(FLAGS) votaciones1d.cpp
vot2d: votaciones2d.cpp
	$(CC) $(FLAGS) votaciones2d.cpp
vot3d: votaciones3d.cpp
	$(CC) $(FLAGS) votaciones3d.cpp
clean:
	rm -f *.gif *.out *.dat
