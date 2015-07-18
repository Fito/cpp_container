IntegerListArray.o: IntegerListArray.h IntegerListArray.cpp
	g++ -c IntegerListArray.cpp

IntegerListLink.o: IntegerListLink.h IntegerListLink.cpp
	g++ -c IntegerListLink.cpp

IntegerListSorted.o: IntegerListSorted.h IntegerListSorted.cpp
	g++ -c IntegerListSorted.cpp

IntegerListVector.o: IntegerListVector.h IntegerListVector.cpp
	g++ -c IntegerListVector.cpp

List.o: List.h List.cpp
	g++ -c List.cpp

clean:
	rm -f *.o


