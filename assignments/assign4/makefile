driver: driver.o MyString.o
	g++ driver.o MyString.o -o driver

driver.o: driver.cpp MyString.h
	g++ -c driver.cpp

MyString.o: MyString.cpp MyString.h 
	g++ -c MyString.cpp

clean:
	rm -f menu *.o

