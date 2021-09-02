fib: Fibbonaci.o fibbMain.o
        g++ -o fib Fibbonaci.o fibbMain.o
        chmod 755 fib

Fibbonaci.o: Fibbonaci.cpp Fibbonaci.h
        g++ -c Fibbonaci.cpp

fibbMain.o: fibbMain.cpp Fibbonaci.h
        g++ -c fibbMain.cpp

clean:
        rm -f *.o fib