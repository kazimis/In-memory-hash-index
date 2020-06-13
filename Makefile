all: hashApp

hashApp: main.o ExtensibleHashTable.o Bucket.o
	g++ -Wall -o hashApp main.o ExtensibleHashTable.o Bucket.o

main.o: main.cpp
	g++ -c main.cpp

ExtensibleHashTable.o: ExtensibleHashTable.cpp ExtensibleHashTable.h
	g++ -c -std=c++11 ExtensibleHashTable.cpp

Bucket.o: Bucket.cpp Bucket.h
	g++ -c Bucket.cpp

clean:
	rm -f hashApp *.o
all: hashApp


