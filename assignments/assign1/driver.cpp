#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sphere.h"

using namespace std;

void printSummaries(Sphere sphere1, Sphere sphere2, Sphere sphere3, Sphere sphere4, Sphere sphere5, int precision= 2);

int main() {

    // seed the random number generator
    srand((time(0)));

    int precision = 0; // Precision variable for summary testing
    double growAmount = 2.5;  // Tracking variable for grow
    double shrinkAmount = 2.0;  // Tracking variable for shrink

    // Create 5 sphere objects
    Sphere sphere1, sphere2, sphere3, sphere4, sphere5;
    sphere1 = Sphere();
    sphere2 = Sphere(2.5);
    sphere3 = Sphere(1.54);
    sphere4 = Sphere(5.0);
    sphere5 = Sphere(32.32);

    precision = 5;
    printSummaries(sphere1, sphere2, sphere3, sphere4, sphere5, precision);

    cout<< "--> Growing Spheres by " << growAmount << endl;

    sphere1.grow(growAmount);
    sphere2.grow(growAmount);
    sphere3.grow(growAmount);
    sphere4.grow(growAmount);
    sphere5.grow(growAmount);

    precision = 2;
    printSummaries(sphere1, sphere2, sphere3, sphere4, sphere5, precision);

    cout<< "--> Shrinking Spheres by " << shrinkAmount<< endl;

    sphere1.shrink(shrinkAmount);
    sphere2.shrink(shrinkAmount);
    sphere3.shrink(shrinkAmount);
    sphere4.shrink(shrinkAmount);
    sphere5.shrink(shrinkAmount);

    printSummaries(sphere1, sphere2, sphere3, sphere4, sphere5);

    return 0;
}


/*
 * This function receives five Spheres and prints their summaries
 */
void printSummaries(Sphere sphere1, Sphere sphere2, Sphere sphere3, Sphere sphere4, Sphere sphere5, int precision){
    cout << "Print summaries" << endl;

    cout<< "Summary Sphere " << 1 << ""<< endl;
    sphere1.printSummary(precision);
    cout << endl;

    cout<< "Summary Sphere " << 2 << ""<< endl;
    sphere2.printSummary(precision);
    cout << endl;

    cout<< "Summary Sphere " << 3 << ""<< endl;
    sphere3.printSummary(precision);
    cout << endl;

    cout<< "Summary Sphere " << 4 << ""<< endl;
    sphere4.printSummary(precision);
    cout << endl;

    cout<< "Summary Sphere " << 5 << ""<< endl;
    sphere5.printSummary(precision);
    cout << endl;
}
