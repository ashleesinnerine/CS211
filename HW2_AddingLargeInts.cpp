/*
Ashlee Sinnerine
February 3rd, 2025
Adding Large Integers


*/

#include <iostream>
using namespace std;

int main()
{
    string n1, n2, result = "";
    int carry = 0;
    
    cout << "Enter two integers (up to 100 digits): \n";
    cin >> n1;
    cin >> n2;
    
    int x = n1.size() - 1;
    int y = n2.size() - 1;
    
    while (x>=0 || y>=0 || carry){
        int d1 = 0, d2 = 0;
        
        if (x>=0){
            d1 =  n1[x] - '0';
            x--;
        }
        
        if (y>=0){
            d2 =  n2[y] - '0';
            y--;
        }
        
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        result = char (sum % 10 + '0') + result;
    }
    
    cout << result << endl;

    return 0;
}