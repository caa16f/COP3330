//Carlos Alfonso	
//10/2/2018
//COP 3330
//Reference object for assignment 2. CPP File.

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>	
#include <cstdio>
#include <string>
#include "Reference.h"

using namespace std;


//Normal Constructor
Reference::Reference(string title1, string firstName1, string lastName1, int MOP1, 
                        int DOP1, int YOP1, int pages1, int citationCount1, char type1,
                                string venue1, string city1 , string country1){

	
	title = title1;	
        firstName = firstName1;
        lastName = lastName1;;
        MOP = MOP1;
        DOP = DOP1;
        YOP = YOP1;
        pages = pages1;
        citationCount = citationCount1;
        type = type1;
        venue = venue1;
        city = city1;
        country = country1;
	formatSetting = 'D';

	if(MOP1 > 12 || MOP1 <= 0){
		cout << "Invalid Month of publication, setting to defualt MO111P = 1";
		MOP1 = 1;
	}
	 if(DOP1 > 31 || DOP1 <= 0){                                               
                cout << "Invalid Day of publication, setting to defualt DOP = 1";
                DOP1 = 1;

        }
	//This is why y2k happened
	if(YOP1 <= 0 || YOP1 > 9999){
		cout << "Invalud Year of Publication, setting to defualt YOP = 2000";
		YOP1 = 2000;
	}

	//Setting defualt char for type
	if(type1 == 'c'){
		type1 = 'C';
	}else if(type1 == 'j'){
		type1 = 'J';
	}

	if(title1.length() > 100 || title1.length() == 0){
		cout << "Title length invalid";
	}
	if(firstName1.length() > 35 || firstName1.length() == 0){
		cout << "First Name length invalid";
	}
	if(lastName1.length() > 35 || lastName1.length() == 0){
                cout << "Last Name length invalid";
        }
	if(city1.length() > 35 || city1.length() == 0){
                cout << "City length invalid";
        }
	if(country1.length() > 35 || country1.length() == 0){
                cout << "Country length exceeds expectations";
        }
	
	
}

//Reference constructor
Reference::Reference(int newCitationCount){
	title = "No Title";
	firstName = "Blank";
	lastName = "Anonymous";
	MOP = 1;
	DOP = 1;
	YOP = 2000;
	pages = 10;
	citationCount = newCitationCount;
	type = 'J';
	venue = "EMSE";
	city = "New York";
	country = "United States";
	formatSetting = 'D';
}


//Accessor functions

string Reference::getTitle(){
	return this->title;
}

string Reference::getLastname(){
	return this->lastName;
}

int Reference::getMonth(){
	return this->MOP;
}	

int Reference::getDay(){
	return this->DOP;
}
int Reference::getYear(){
	return this->YOP;
}
string Reference::getAuthor(){
	return this->firstName + " " + this->lastName;
}

//Non mandatory getters for making output easier
char Reference::getType(){
	return this->type;
}

string Reference::getVenue(){
	return this->venue;
}

string Reference::getCity(){
	return this->city;
}

string Reference::getCountry(){
	return this->country;
}

int Reference::getPages(){
	return this->pages;
}

int Reference::getCitationCount(){
	return citationCount;
}

string Reference::getFirstname(){
	return firstName;
}

//Mutator Functions
bool Reference::setTitle(string newTitle){
	 if(newTitle.length() > 100){
        	return false;
	}

	this->title = newTitle;
	return true;
}

bool Reference::setFirstname(string newFirstName){
	int counter = 0;
	int i = 0;
	if(newFirstName.length() > 35 || newFirstName.empty()){
		return false;	
	}
	///Convert to cstring and check to see if the string is all whitespace, false if so
	char * temp = new char[newFirstName.length()];
	strcpy(temp, newFirstName.c_str());
	while(i < newFirstName.length()){
		if(isspace(temp[i]) != 0){
			counter++;
		}		
		i++;
		if(counter == newFirstName.length()){
			return false;
		}
	}
	

	this->firstName = newFirstName;
	return true;
}

bool Reference::setLastname(string newLastName){
	if(newLastName.length() > 35 || newLastName.empty()){
                return false;
        }

        this->lastName = newLastName;
        return true;
}

bool Reference::setMonth(int newMonth){
	if(newMonth > 12 || newMonth < 0){
		return false;
	}
	this->MOP = newMonth;
	return true;
}
bool Reference::setDay(int newDay){
        if(newDay > 31 || newDay < 0){
		return false;
        }
        this->DOP = newDay;
        return true;
}
bool Reference::setYear(int newYear){
        if(newYear > 9999  || newYear < 0){
                return false;
        }
        this->YOP = newYear;
        return true;
}
bool Reference::setCitationCount(int newCitationCount){
	if(newCitationCount < 0){
		return false;
	}
	this->citationCount = newCitationCount;
	return true;
}

bool Reference::setType(char newType){
	if(newType != 'C' && newType != 'J'){
		return false;
	} 	
	this->type = newType;
	return true;
}

//SHOW FUNCTION
void Reference::show(){

	
	//DEFUALT FORMAT
	if(formatSetting == 'D'){
	
		cout << getTitle() << " by " << getLastname() << ", " << getFirstname() << "\n";
	

	//FULL FORMAT FOR JOURNALS
	}else if(formatSetting == 'F' && getType() == 'J' ){
		cout << getLastname() << ", " << getFirstname() << " \""  << getTitle() <<  "\" ";
		//2nd and 3rd cout for ease of reading
		cout << "(" << getYear() << ") in " << getVenue() << ", " << getCity() << ", " << getCountry() << ", pp. " << "\n";
		cout << getPages() << " " << "(Cited: " << getCitationCount() << " times)";
	//FULL FORMAT FOR CONFERENCES
	}else if(formatSetting == 'F' && getType() == 'C' ){
		cout << getLastname() << ", " << getFirstname() << " \""  << getTitle() << "\" " ; 
                cout << "(" << getYear() << ") in Proceedings of " << getVenue() << ", " << getCity() << ", " << "\n";
		cout << getCountry() << ", pp. " << getPages() << " " << "(Cited: " << getCitationCount() << " times)" << "\n";
	
	//ABBREVIATED FORMAT
	}else if(formatSetting == 'A'){
		cout << getLastname() << "(" << getYear() << ")" << "\n";

	//LONG FORMAT
	}else if(formatSetting == 'L'){
		cout << "Title: " << getTitle() << "\n";
		cout << "Author: " << getAuthor() << "\n";
		cout << "Publication Date: " << getMonth() << "/" << getDay() << "/" << getYear() << "\n";
		cout << "Published at: " << getVenue() << ", " << getCity() << ", " << getCountry();
	}

}


//Set Format function
bool Reference::setFormat(char newFormat){
	//Check to see if newFormat is a valid character
	if(newFormat != 'D' && newFormat != 'd' &&
		newFormat != 'F' && newFormat != 'f' &&
			newFormat != 'A' && newFormat != 'a' &&
				newFormat != 'L' && newFormat != 'l'){
		cout << "Invalid new format" << "\n";
		return false;
	}
		this->formatSetting = newFormat;
		return true;
}



void Reference::parse(string CSV){
	bool loop = true;
	char* holder;	
	char * temp = new char[CSV.size()+1];
 	strcpy(temp, CSV.c_str());	
	
 while(loop){						//Returns a pointer set to holder.
	holder = strtok(temp, ",");
	if(holder ==NULL){
		loop = false;
		break;
	}
	setTitle(holder);
	
	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
	firstName= holder;
	
	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
        lastName = holder;

	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
        DOP = atoi(holder);
	
	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
        MOP = atoi(holder);

	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
        YOP = atoi(holder);

	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
        pages = atoi(holder);
	
	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
        citationCount = atoi(holder);

	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
	type = *holder;
        
	holder =strtok(NULL, ",");
	 if(holder == NULL){
                loop = false;
		break;
        }
        venue = holder;

	holder =strtok(NULL, ",");
	if(holder == NULL){
		loop = false;
		break;
	}
        city = holder;
	
	holder =strtok(NULL, ",");
	if(holder == NULL){
		loop = false;
		break;
	}
        country = holder;
	}
	
}

//Updates citation counter, makes sure that citation count cannot be < 0
bool Reference::updateCitationCount(int newCitation = 1){
	
	if(citationCount + newCitation <0){
		return false;
	} else {
		citationCount = citationCount + newCitation;
		return true;
	}
}

//Checks each individual value in Reference objects to see if their equal, false otherwise
bool equals(Reference x, Reference y){
	if(x.getTitle() != y.getTitle()){
		return false;
	} else if(x.getFirstname() != y.getFirstname()){
		return false;
	} else if(x.getLastname() != y.getLastname()){
		return false;
	} else if(x.getMonth() != y.getMonth()){
		return false;
	} else if(x.getDay() != y.getDay()){
		return false;
	} else if(x.getYear() != y.getYear()){
		return false;	
	} else if(x.getPages() != y.getPages()){
		return false;
	} else if(x.getCitationCount() != y.getCitationCount()){
		return false;
	} else if(x.getType() != y.getType()){
		return false;
	} else if(x.getVenue() != y.getVenue()){
		return false;	
	} else if(x.getCity() != y.getCity()){
		return false;
	} else if(x.getCountry() != y.getCountry()){
		return false;
	} else {
		return true;
	}
}
