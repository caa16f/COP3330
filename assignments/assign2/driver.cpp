//
// Created by Esteban Parra on 9/16/18.
//

#include <iostream>

#include "Reference.h"

using namespace std;

void compareReferences(Reference ref1, Reference ref2);

int main(){

    Reference p1;
    Reference p2(125);

    cout<< "---- Reference created with the default constructor ---- "<< endl;
    p1.show();

    p1.setTitle("Black Clover");

    cout<< endl << "---- Testing Long format ---- "<< endl;
    p1.setFormat('L');

    p1.show();

    cout<<  endl<< "---- Testing Default format ---- "<< endl;
    p1.setFormat('D');

    p1.show();

    cout<< endl<< "---- Testing Abbreviated format ---- "<< endl;
    p1.setFormat('A');

    p1.show();

    // Testing some mutators
    p1.setFirstname("Emily-Grace");
    p1.setYear(34);
    p1.setType('C');

    cout<< endl<< "---- Testing Full format ---- "<< endl;
    p1.setFormat('F');
    p1.show();


    cout<< endl<< "---- Testing Parsing and mutators ---- "<< endl;
    string input = "New,Olivia Taylor,Dudley,11,4,1986,23,33,J,PSE";
    p1.parse(input);
    p1.setType('c');
    p1.setFirstname("    ");
    p1.setLastname("");
    p1.show();

    cout<< endl << "---- Testing equals ---- "<< endl;
    Reference r1,r2;

    compareReferences(r1,r2);
    compareReferences(p1,r2);

    return 0;
}


void compareReferences(Reference ref1, Reference ref2){
    if(equals(ref1, ref2)){
        cout << "The references are equal" << endl;
    }else{
        cout << "The references are different" << endl;
    }
}
