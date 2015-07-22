CMD=g++
OBJS=IntegerListArray.o IntegerListVector.o IntegerListLinked.o IntegerListSorted.o

listTest: listTest.cpp IntegerListArray.h IntegerListVector.h IntegerListLinked.h \
	  IntegerListSorted.h List.h List.hxx Node.h $(OBJS)
	$(CMD) -o listTest listTest.cpp $(OBJS)

IntegerListArray.o: IntegerListArray.cpp IntegerListArray.h
	$(CMD) -c IntegerListArray.cpp

IntegerListVector.o: IntegerListVector.cpp IntegerListVector.h
	$(CMD) -c IntegerListVector.cpp

IntegerListLinked.o: IntegerListLinked.cpp IntegerListLinked.h Node.h
	$(CMD) -c IntegerListLinked.cpp

IntegerListSorted.o: IntegerListSorted.cpp IntegerListSorted.h Node.h
	$(CMD) -c IntegerListSorted.cpp

clean:
	rm -f listTest IntegerListArray.o IntegerListVector.o \
		IntegerListLinked.o List.o IntegerListSorted.o

run: listTest
	./listTest
