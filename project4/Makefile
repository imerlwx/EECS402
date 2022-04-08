all: proj4.exe

proj4.o: proj4.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h LIFOStackClass.h
	g++ -std=c++98 -Wall -c proj4.cpp -o proj4.o

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h
	g++ -std=c++98 -Wall -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h
	g++ -std=c++98 -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o

LIFOStackClass.o: LIFOStackClass.cpp LIFOStackClass.h
	g++ -std=c++98 -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o

proj4.exe: LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o proj4.o
	g++ -std=c++98 LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o proj4.o -o proj4.exe

clean:
	rm -f *.o *.exe