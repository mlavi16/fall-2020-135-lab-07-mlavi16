OBJECTS = unindent.o

main: main.o ${OBJECTS}
	g++ -o main main.o ${OBJECTS}

tests: tests.o ${OBJECTS}
	g++ -o tests tests.o ${OBJECTS}

main.o: main.cpp unindent.h

unindent.o: unindent.cpp unindent.h

tests.o: tests.cpp doctest.h unindent.h

clean:
	rm -f main.o tests.o ${OBJECTS}

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests