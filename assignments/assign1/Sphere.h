//-------------------SPHERE.H------------------------
// CARLOS ALFONSO
// Section 1

class Sphere
{
public:
	Sphere();
	//Constuctor with parameters. Color defaulted to unused character 'T'					
	Sphere(double radius, char color = 'T');
	
	// Input/Output routine
	void printSummary(int precision);
	

	// Accessors
	double getRadius(double radius);
	char getColor();
	double getDiameter(double radius);
	double getSurfaceArea(double radius);
	double getVolume(double radius);

	// Mutators 
	void setRadius(double newRadius);
	void setColor(char newColor);
	void grow(double addRadius);
	void shrink(double subRadius);
	void randomizeColor();
	
private:
	//Private variables
	double radius;
	char color;

};
