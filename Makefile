CC=g++
CCFLAGS= -std=c++11 -fsanitize=address -fsanitize=leak -fsanitize=undefined

vot1: votaciones1.cpp
	$(CC) $(CCFLAGS) votaciones1.cpp
