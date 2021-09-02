
// Created by Esteban Parra on 9/10/18.
//

#ifndef COP3330_FALL2018_FIBBONACI_H
#define COP3330_FALL2018_FIBBONACI_H


class Fibbonaci {

public:
    Fibbonaci();
    Fibbonaci(int val0, int val1 = 2);
    int getNext(int valueA, int valueB);
    int getNthValue(int n);

private:
    int value1;
    int value0;
    int val0;
    int val1;
};


#endif //COP3330_FALL2018_FIBBONACI_H
