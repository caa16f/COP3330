//
// Created by Esteban Parra on 9/10/18.
//

#include "Fibbonaci.h"

//Default constructor
Fibbonaci::Fibbonaci(){
	value0 = 1;
	value1 = 1;
}
//New Constructor
Fibbonaci::Fibbonaci(int value0, int val1 = 2){
	value0 = val0;
	value1 = val1;
}

/*
 * This method gets the next value in the series by adding up the two
 * values passed as parameters
 */
int Fibbonaci::getNext(int valueA, int valueB){
    int nextValue = valueA + valueB;
    return nextValue;
}
/*
 * This method computes the nth value on the series
 */
int Fibbonaci::getNthValue(int n){

    if(n == 0){
        return value0;
    }else if(n == 1){
        return value1;
    }else{
        return getNext(getNthValue(n-1), getNthValue(n-2));
    }
}
