/*
Ashlee Sinnerine
April 30th, 2025
Implementing Numerical Integration Using Function Pointers

The problem is to write a function “integrate” with prototype:
typedef double (*FUNC)(double);
double integrate(FUNC f, double a, double b);
so that when it is passed a function f and bounds a and b, the call:
integrate(f, a,b) will return the value of the definite integral of f evaluated between a and b.
*/

#include <iostream>
using namespace std;

typedef double (*FUNC)(double);
double integrate(FUNC f, double a, double b){
    double delta = 0.0001; // change in horizontal position x
    double sum = 0.0; // sum of areas
    double x = a; // starting point
    while (x < b) {
        sum += f(x) * delta; // area of rectangle (height * width)
        // f(x) is the height of the rectangle, delta is the width
        x+= delta; // move to next rectangle
    }
    return sum; // return total area
}

double line(double x){
return x;
}

double square(double x){
return x*x;
}

double cube(double x){
return x*x*x;
}

int main() {
    cout<<"The integral of f(x) = x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl;
    cout<<"The integral of f(x) = x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
    cout<<"The integral of f(x) = x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;
    return 0;
}