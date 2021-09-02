//---------------------------SPHERE.CPP---------------------
//CARLOS ALFONSO
//SECTION 1
//
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Sphere.h"

using namespace std;

//Default constructor
Sphere::Sphere()
{
	radius = 1.0;
	randomizeColor();
}

//Contructor with parameters, color defaulted to T
Sphere::Sphere(double radius, char color){
	
	//Radius must be greater than 0.0
	if(radius <= 0.0){
		radius = 1.0;
	}
	
	//Was getting errors when running driver.cpp. Radius of spheres 2 - 5 would not populate without this line
	Sphere::radius = radius;
	
	//If color is default 'T' or anything other than the allowed char then give random color	
	if(color == 'T' ||
	color != 'B' && color != 'b' && 
	color != 'R' && color != 'r' && 	
	color != 'P' && color != 'p' && 
	color != 'Y' && color != 'y' && 
	color != 'G' && color != 'g' && 
	color != 'L' && color != 'l' &&
	color != 'M' && color != 'm' )
		{	
			randomizeColor();
		}

}

//Getters
double Sphere::getRadius(double radius){
	return radius;
}

char Sphere::getColor(){
	return color;
}

double Sphere::getDiameter(double radius){
	return (2.0 * radius);
}

double Sphere::getSurfaceArea(double radius){
	
	return (4.0*3.14159*(radius*radius));
}

double Sphere::getVolume(double radius){
	return ((4.0/3.0) * 3.14159 * (radius*radius*radius));
}


//Setters 
void Sphere::setRadius(double newRadius){
	if(newRadius <= 0){
	cout << "New radius must be greater than 0.0";
	}else {
	radius = newRadius;
	}	
}

void Sphere::setColor(char newColor){
	 if(newColor == ' ' ||
        newColor != 'B' && newColor != 'b' &&
        newColor != 'R' && newColor != 'r' &&
        newColor != 'P' && newColor != 'p' &&
        newColor != 'Y' && newColor != 'y' &&
        newColor != 'G' && newColor != 'g' &&
        newColor != 'L' && newColor != 'l' &&
        newColor != 'M' && newColor != 'm' )
        {
        cout << "That is not a valid color";
        }else{
	color = newColor;
	}
}

//Manipulators
void Sphere::grow(double addRadius){
        if((radius + addRadius) <= 0.0){
                cout << "Radius must be greater than 0.0";
        }else{
        radius = radius + addRadius;
        }
}

void Sphere::shrink(double subRadius){
        if((radius - subRadius) <= 0.0){
                cout << "Radius must be greater than 0.0";
        }else{  
        radius = radius - subRadius;
        }
}

//Printsummary
void Sphere::printSummary(int precision){
	
	if(precision < 1 || precision > 5){
		precision = 2;
	}
	
	cout << fixed << showpoint << setprecision(precision);
	
	cout << "Radius:\t\t" << getRadius(radius) << "\n";


	 if(color == 'B' || color == 'b'){
		cout << "Color:\t 	Blue" << "\n";
	}else if(color == 'R' || color == 'r'){
		cout << "Color:\t 	Red" << "\n";
	}else if(color == 'P' || color == 'p'){
		cout << "Color:\t 	Purple" << "\n";
	}else if(color == 'Y' || color == 'y'){
		cout << "Color:\t 	Yellow" << "\n";
	}else if(color == 'G' || color == 'g'){
		cout << "Color:\t 	Green" << "\n" ;
	}else if(color == 'L' || color == 'l'){
		cout << "Color:\t 	Black" << "\n";
	}else if(color == 'M' || color == 'm'){
		cout << "Color:\t 	Maroon" << "\n";
	}

	cout << "Diameter:	" << getDiameter(getRadius(radius)) << "\n";
	cout << "Surface Area:	" << getSurfaceArea(getRadius(radius)) << "\n";
	cout << "Volume:\t	" << getVolume(getRadius(radius)) << "\n";
	 
}

//Randomizes the color of the sphere object when called
void Sphere::randomizeColor(){
	int random = rand() % 7 + 1;

	if(random == 1){
		color =  'B';
	}else if(random == 2){
		color = 'R';
	}else if(random == 3){
		color = 'P';
	}else if(random == 4){
		color =  'Y';
	}else if(random == 5){
		color = 'G';
	}else if(random == 6){
		color = 'L';
	}else if(random == 7){
		color = 'M';
	} else {
	 cout << "Something went wrong in randomizeColor()";
}
}
//---------------------------------------------------------------------------------------------------
