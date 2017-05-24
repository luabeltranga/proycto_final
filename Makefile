CC=g++
FLAGS= -std=c++11 -fsanitize=address -fsanitize=leak -fsanitize=undefined  -O2
#FLAGS= -std=c++11 -ggdb -g
vot1d: votaciones1d.cpp
	$(CC) $(FLAGS) votaciones1d.cpp

vot2dprob: votaciones2d_probvsdens.cpp
	$(CC) $(FLAGS) votaciones2d_probvsdens.cpp

vot2dtime: votaciones2d_timevsN.cpp
	$(CC) $(FLAGS) votaciones2d_timevsN.cpp

vot3d: votaciones3d.cpp
	$(CC) $(FLAGS) votaciones3d.cpp

vot2dV2: votaciones2d_V2.cpp
	$(CC) $(FLAGS) votaciones2d_V2.cpp

vot3dV2: votaciones3d_V2.cpp
	$(CC) $(FLAGS) votaciones3d_V2.cpp

clean:
	rm -f *.gif *.out *.dat *~ *.log
