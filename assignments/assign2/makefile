

Ref: Reference.o driver.o
	g++ -o Ref driver.o Reference.o

driver.o: driver.cpp
	g++ -c driver.cpp

Reference.o: Reference.h Reference.cpp
		g++ -c Reference.cpp


clean: 
	rm *.p Ref
