/*
Ashlee Sinnerine
February 3rd, 2025
Perfect Square

Write a program to find and print the first perfect square (i*i) 
whose last two digits are both odd.
*/

#include <iostream>
using namespace std;

int main() {
    int i=0;
    int lastDigit, secondLastDigit;
    
    while (i<100){
        lastDigit = (i*i) % 10;
        secondLastDigit = ((i*i) / 10) % 10;

        if ((lastDigit % 2 == 1) && (secondLastDigit % 2 == 1)){
            cout<< "i is: " << i << endl;
            return 0;
        }
        i++;
    }
    
    cout << "There is no solution." << endl;

    return 0;
}