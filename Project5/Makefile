all: proj5.exe

proj5.o: project5.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h CarClass.h EventClass.h random.h IntersectionSimulationClass.h
	g++ -std=c++98 -Wall -c project5.cpp -o proj5.o

CarClass.o: CarClass.cpp CarClass.h
	g++ -std=c++98 -Wall -c CarClass.cpp -o CarClass.o

EventClass.o: EventClass.cpp EventClass.h
	g++ -std=c++98 -Wall -c EventClass.cpp -o EventClass.o

random.o: random.cpp random.h
	g++ -std=c++98 -Wall -c random.cpp -o random.o

IntersectionSimulationClass.o: IntersectionSimulationClass.cpp IntersectionSimulationClass.h
	g++ -std=c++98 -Wall -c IntersectionSimulationClass.cpp -o IntersectionSimulationClass.o

proj5.exe: CarClass.o EventClass.o random.o IntersectionSimulationClass.o proj5.o
	g++ -std=c++98 CarClass.o EventClass.o random.o IntersectionSimulationClass.o proj5.o -o proj5.exe

clean:
	rm -f *.o *.exe