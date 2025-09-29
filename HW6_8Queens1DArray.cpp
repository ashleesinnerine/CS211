/*
Ashlee Sinnerine
February 26th, 2025
8 Queens 1D Array

Complete the 8 Queens 1-Dimensional Array Program with backtracking
with gotos like we did in class.

*/

#include <iostream>
using namespace std;

int main(){
    int q[8], c=0, solutionNum=0;
    
    //place the queen in the first row and column
    q[0]=0;
    
    nextCol:
        c++;
        if(c==8) goto print;
        q[c]=-1;
        
    nextRow:
        q[c]++;
        if (q[c]==8) goto backtrack;
        
        //tests
        for (int i=0; i<c; i++){
            if (q[c]==q[i] || (c-i)==abs(q[c]-q[i])) goto nextRow;
        }
        
        goto nextCol;
        
    backtrack:
        c--;
        if (c==-1){
            cout<<"Total number of solutions: "<<solutionNum<<endl;
            return 0;
        }
        goto nextRow;

    print:
        solutionNum++;
        cout<<"Solution #"<< solutionNum << endl;
        
        //print chessboard
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (q[j]==i) cout<<"1 ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        goto backtrack;
    
    return 0;
}