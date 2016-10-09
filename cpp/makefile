all: Hello.o Test.o
	g++ Hello.o Test.o

Test.o: Test.cpp Hello.h
	g++ -c Test.cpp

Hello.o: Hello.cpp Hello.h
	g++ -c Hello.cpp

clean:
	rm -rf a.exe Hello.o Test.o
