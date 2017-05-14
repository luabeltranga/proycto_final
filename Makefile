CC=g++
#CCFLAGS= -std=c++11 -fsanitize=address -fsanitize=leak -fsanitize=undefined -ggdb
CCFLAGS= -std=c++11 -ggdb	
vot1: votaciones1.cpp
	$(CC) $(CCFLAGS) votaciones1.cpp
clean:
	rm -f *.gif *.out *.dat
