/*
Ashlee Sinnerine
May 16th, 2025
Rat Class

Starting with the Rat class (see Handouts) do the following:

1. Add the following operators to the class:
    operator-()
    operator*()
    operator/()

2. Make sure Rats are reduced to lowest terms. So if a Rat is 2/4 it should be
reduced to 1⁄2.

3. If a Rat represents an “improper fraction” (i.e. numerator >denominator) print
the Rat as a “mixed number.” So 6/4 will be printed as 1 1⁄2.

*/

#include <iostream>
using namespace std;

class Rat {
    private:
        int n;
        int d;
    public:
        //constructors

        //default constructor
        Rat() {
            n = 0;
            d = 1;
        }

        //2 parameter constructor
        Rat(int i, int j) {
            n = i;
            d = j;
            if(d == 0) {
                cout << "Denominator cannot be zero. Setting to 1." << endl;
                d = 1;
            }
            reduce();
        }

        //conversion constructor
        Rat(int i) {
            n = i;
            d = 1;
        }

        //accessor functions (usually called get() and set(...))
        int getN() {
            return n;
        }

        int getD() {
            return d;
        }

        void setN(int i) {
            n = i;
            reduce();
        }

        void setD(int i) {
            d = i;
            if(d == 0) {
                cout << "Denominator cannot be zero. Setting to 1." << endl;
                d = 1;
            }
            reduce();
        }

        //arithmetic operators
        Rat operator+(Rat r) {
            Rat result;
            result.n = n * r.d + d * r.n;
            result.d = d * r.d;
            result.reduce();
            return result;
        }

        Rat operator-(Rat r) {
            Rat result;
            result.n = n * r.d - d * r.n;
            result.d = d * r.d;
            result.reduce();
            return result;
        }

        Rat operator*(Rat r) {
            Rat result;
            result.n = n * r.n;
            result.d = d * r.d;
            result.reduce();
            return result;
        }

        Rat operator/(Rat r) {
            Rat result;
            result.n = n * r.d;
            result.d = d * r.n;
            result.reduce();
            return result;
        }

        // the GCD (Euclid's algorithm) finds the largest common divisor
        int gcd(int a, int b) {
            if (b == 0) {
                return a;
            }
            return gcd(b, a % b);
        }

        //reduce the fraction to lowest terms
        void reduce() {
            int g = gcd(n, d);
            n = n / g;
            d = d / g;
            if (d < 0) { // ensure the denominator is always positive
                n = -n;
                d = -d;
            }
        }

        //2 overloaded i/o operators
        friend ostream& operator<<(ostream& os, Rat r);
        friend istream& operator>>(istream& is, Rat& r);

};  // end of class Rat

//operator<<() is NOT a member function but since it was declared a friend of Rat
//it can access the private members of Rat
//operator<<() prints the Rat in the form n/d
ostream& operator<<(ostream& os, Rat r){
    r.reduce();
    
    if (r.n == 0) {
        os << 0;
    } else if (r.n >= r.d) {
        int whole = r.n / r.d;
        int remainder = r.n % r.d;
        if (remainder != 0)
            os << whole << " " << remainder << "/" << r.d;
        else
            os << whole;
    } else {
        os << r.n << "/" << r.d;
    }
    
    return os;
}

//operator>>() is NOT a member function but since it was declared a friend of Rat
//it can access the private members of Rat
//operator>>() reads the Rat in the form n/d
istream& operator>>(istream& is, Rat& r){
    char c;
    is>>r.n>> c >>r.d;
    if (r.d == 0) {
        cout << "Denominator cannot be zero. Setting to 1." << endl;
        r.d = 1;
    }
    r.reduce();
    return is;
}

int main() {
    Rat r1, r2, r3;
    cout << "Enter a fraction in the form n/d: ";
    cin >> r1;
    cout << "Enter another fraction in the form n/d: ";
    cin >> r2;
    r3 = r1 + r2;
    cout << "The sum is: " << r3 << endl;
    r3 = r1 - r2;
    cout << "The difference is: " << r3 << endl;
    r3 = r1 * r2;
    cout << "The product is: " << r3 << endl;
    r3 = r1 / r2;
    cout << "The quotient is: " << r3 << endl;

    return 0;
}