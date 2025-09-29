/*
Ashlee Sinnerine
May 7th, 2025
N Queens

Write a function that inputs an integer n and returns the number of solutions to the “n queens” problem. Your function should use the one dimensional representation for the board, the algorithm we discussed in class, and no gotos.

*/
#include <iostream>
using namespace std;

//check if the queen can be placed in the column
//returns true if the queen can be placed, false otherwise
bool ok(int q[], int col){ 
	for(int i=0; i<col; i++){
		if((q[i]==q[col]) || ((col-i)==abs(q[col]-q[i]))){ 
			return false;
		}
	}
	return true;	
}

int nQueens(int n) {
    int *q = new int[n], c=0, solutionNum=0;
    q[0]=0;                         //place first queen in first row
    while(c>=0){ 
        c++;                        
        if (c==n){                //if all queens are placed
            solutionNum++;          //Add to solution count
            c--;                    //backtrack to find more solutions
        }
        else {
            q[c]=-1;                //place new queen in first row
        }
        
        while (c>=0){               //try placing queen in each row
        q[c]++;                     //move to next row
        if (q[c] == n) c--;       //if row is out of bounds, backtrack
        else if (ok(q,c)) break;    //if queen is ok, move to next column
        }                           
    }
    delete[] q;                   //free memory
    return solutionNum;
}

int main(){
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    
    for (int i = 1; i <= n; i++) {
        cout << "There are " << nQueens(i) << " solutions to the " << i << " queens problem." << endl;
    }   
    return 0;
}