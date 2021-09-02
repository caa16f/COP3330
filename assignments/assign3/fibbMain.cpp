//
// Created by Esteban Parra on 9/10/18.
//
#include "Fibbonaci.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    Fibbonaci f1;

    for (int i=0; i<10; i++) {
        cout << setw(3) << f1.getNthValue(i);
    }
    return 0;
}

