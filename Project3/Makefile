all: <proj3.exe>

<proj3.o>: <proj3.cpp> <ColorImageClass.h> <MessageFileClass.h> <userInterface.h> <RowColumnClass.h> <ColorClass.h> <constants.h>
	g++ -std=c++98 -Wall -c <proj3.cpp> -o <proj3.o>

<ColorImageClass.o>: <ColorImageClass.cpp> <ColorImageClass.h>
	g++ -std=c++98 -Wall -c <ColorImageClass.cpp> -o <ColorImageClass.o>

<MessageFileClass.o>: <MessageFileClass.cpp> <MessageFileClass.h>
	g++ -std=c++98 -Wall -c <MessageFileClass.cpp> -o <MessageFileClass.o>

<userInterface.o>: <userInterface.cpp> <userInterface.h>
	g++ -std=c++98 -Wall -c <userInterface.cpp> -o <userInterface.o>

<RowColumnClass.o>: <RowColumnClass.cpp> <RowColumnClass.h>
	g++ -std=c++98 -Wall -c <RowColumnClass.cpp> -o <RowColumnClass.o>

<ColorClass.o>: <ColorClass.cpp> <ColorClass.h>
	g++ -std=c++98 -Wall -c <ColorClass.cpp> -o <ColorClass.o>

<proj3.exe>: <ColorImageClass.o> <MessageFileClass.o> <userInterface.o> <RowColumnClass.o> <ColorClass.o>
	g++ -std=c++98 <ColorImageClass.o> <MessageFileClass.o> <userInterface.o> <RowColumnClass.o> <ColorClass.o> -o <proj3.exe>

clean:
	rm -f *.o *.exe

