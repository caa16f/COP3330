//
// Created by Carlos on 11/25/2018.
// Section 9
#include "MyString.h"
#include <cstring>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <istream>


using namespace std;
//Creates default empty string object
MyString::MyString() {
    size = 0;
    string = new char[size];
    string[0] = '\0';
}

MyString::~MyString(){
    delete [] string;
}

MyString::MyString(const char* c) {
    size = strlen(c);
    string = new char[size];
    strcpy(string, c);
}

MyString::MyString(int number) {
    //Determine the number of digits in "Number" use this to change the size of "string"
    int numDigits = 0;
    int temp = number;

    while(temp > 0){
        temp /= 10;
        numDigits++;
    }
    this->string = new char[numDigits+1];
    this->size = numDigits;
    int i =0;
   while(number > 0){
       string[--numDigits] = ((number%10) + '0');
       number = number/10;
   }

}

//Deep Copy Constructor
MyString::MyString(const MyString &temp ){
    size = temp.size;
    string = new char[temp.size];
    for(int i = 0; i < size; i++){
        string[i] = temp.string[i];
    }
}

//Deep Assignment operator
MyString& MyString::operator=(const MyString &temp) {
    int thisSize;
    //Dont self copy
    if(this == &temp)
        return *this;

    delete [] string;
    thisSize = temp.size;

    string = new char[thisSize];
    strncpy(this->string, temp.getCString(), temp.size);
    return *this;

}


const char* MyString::getCString() const {
    return string;
}

int MyString::getLength() const {
    int counter = 0;
    for(int i = 0; i < size; i++){
        if(isspace(string[i])){
            counter++;
        }else {
            counter++;
        }
    }
    return counter;
}

ostream& operator<<(ostream& os, const MyString& s){
   for(int i = 0; i < s.size; i++){
       os << s.string[i];
   }
   return os;
}

istream &operator>>(istream & is, MyString &s) {

    s.size = 20;
    memset(s.string,' ',s.size);
        do{
               is >> s.string;
            if ((s.size - strlen(s.string)) <= 3) {
                s.grow(s.size + 3);
            }
        }while(!isspace(is.get()));
        return is;

}

//munmap_chunk() invalid pointer
istream& getline(istream& is , MyString& s, char delim){

    s.size = 20;
    memset(s.string,' ',s.size);


            is.getline(s.string, s.size, delim);

                if((s.size - strlen(s.string)) <= 3){
                    s.grow(s.size+3);
                }

        return is;
}

bool operator==(const MyString& S1 , const MyString& S2){
   int holder = strcmp(S1.string, S2.string);
   if(holder == 0){
       return true;
   }else{
       return false;
   }
}
bool operator!=(const MyString& S1 , const MyString& S2){
   if(S1 == S2){
       return false;
   }else{
       return true;
   }
}
int MyString::getSize() const {
   return size;
}

bool operator<(const MyString& S1 , const MyString& S2){
   for(int i = 0; i < S1.size ; i++) {
       //Convert all chars in both strings to lowercase
       S1.string[i] = tolower(S1.string[i]);
       S2.string[i] = tolower(S2.string[i]);
   }
       int holder = strcmp(S1.string, S2.string);

       if(holder == 0){
           return false;
       }else if(holder > 0){
           return false;
       }else{
           return true;
       }
}

bool operator>(const MyString& S1 , const MyString& S2) {
   if(S1 < S2){
       return false;
   }else{
       return true;
   }
}

bool operator<=(const MyString& S1 , const MyString& S2) {
   if(S1 < S2 || S1 == S2){
       return true;
   }else{
       return false;
   }
}

bool operator>=(const MyString& S1 , const MyString& S2) {
   if(S1 > S2 || S1 == S2){
       return true;
   }else{
       return false;
   }
}

void MyString::grow(int newMax){
   char * newString = new char[newMax+1];
   for(int i = 0; i < newMax; i++){
           newString[i] = this->string[i];
   }

   delete [] string;

   string = new char[newMax+1];

   strcpy(string, newString);

}


MyString operator+(const MyString& S1, const MyString& S2){
       MyString temp;
       temp.grow((S1.size + S2.size) +1);

       int holder = -1;

       for(int i = 0; i < S1.size; i++){
           temp.string[i] = S1.string[i];
           holder = holder + 1;
       }

       for(int j = holder + 1; j <= S2.size + holder; j++){
           temp.string[j] = S2.string[j-(S1.size)];

       }

       return temp;
}

MyString& MyString::operator+=(const MyString& S1){
   // MyString temp;
    this->grow((S1.size + this->size) +1);
    strcat(this->string, S1.string);
    return *this;
}

char& MyString::operator[] (unsigned int index){

   if(index > this->getLength()){
       this->grow(index+1);
   }
       for(int i = 0; i < this->getLength(); i++){
           if(i == index){
              return this->string[i];
           }
       }
   }


const char& MyString::operator[] (unsigned int index) const{

   if(index > this->getLength() -1 ){
       return '\0';
   }else{
       for(int i = 0; i < size; i++){
           if(i == index){
               return this->string[i];
           }
       }
   }
}

MyString MyString::substring(unsigned int startTerm, unsigned int subLength) const{
   char * temp = new char[this->getLength()];
   strncpy(temp, this->string + startTerm, subLength);
   return  temp;
}

MyString MyString::substring(unsigned int startTerm) const{
   char * temp = new char[this->getLength()];
   strcpy(temp, this->string + startTerm);
   return  temp;
}

MyString& MyString::insert(unsigned int index, const MyString& str){
    int length = strlen(str.string);
    this->grow(size+length);

    if(index > size){
        strcat(this->string, str.string);
    }else{
        for(int i = strlen(string); i >= index; --i){
            string[i+length] = string[i];
        }
        int j = 0;
        for(int i = index; i <= size; i++){
            string[i] = str.string[j];
                    j++;
        }
    }
    return *this;
}

//IndexOf function, uses pointer subtraction to find index
int MyString::indexOf(const MyString &s) const {
        char * str = this->string;
        char * holder = strstr(this->string, s.string);
        int position = holder - str;
        if(holder == '\0'){
            return -1;
        }else{
            return position;
        }
}