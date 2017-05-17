CC=g++
#CCFLAGS= -std=c++11 -fsanitize=address -fsanitize=leak -fsanitize=undefined 
CCFLAGS= -std=c++11 -ggdb -g	
vot1d: votaciones1d.cpp
	$(CC) $(CCFLAGS) votaciones1d.cpp
vot2d: votaciones2d.cpp
	$(CC) $(CCFLAGS) votaciones2d.cpp
vot3d: votaciones3d.cpp
	$(CC) $(CCFLAGS) votaciones3d.cpp
clean:
	rm -f *.gif *.out *.dat
