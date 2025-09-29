/*
Ashlee Sinnerine
March 6th, 2025
8 Queens 1D Array Without Gotos

Do the 8 queens using 1 dimensional array program with 
backtracking **without** gotos, using functions!

*/

#include <iostream>
using namespace std;

//return true if queen in current column is ok
bool ok(int q[], int &c){
    for (int i=0; i<c; i++){
        if (q[c]==q[i] || (c-i)==abs(q[c]-q[i])) return false;
    }
    return true;
}

//prints solutions in a chessboard grid
void print(int q[], int &solutionNum){
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
}


int main(){
    int q[8], c=0, solutionNum=0;
    
    q[0]=0;                         //place first queen in first row
    while(c>=0){ 
        c++;                        //
        if (c==8){                  //if all queens are placed
            print(q,solutionNum);   //print solution
            c--;                    //backtrack to find more solutions
        }
        else {
            q[c]=-1;                //place new queen in first row
        }
         
        while (c>=0){               //try placing queen in each row
        q[c]++;                     //move to next row
        if (q[c] == 8) c--;         //if row is out of bounds, backtrack
        else if (ok(q,c)) break;    //if queen is ok, move to next column
        }                           
    }

    cout << "Total number of solutions: " << solutionNum << endl;
    return 0;
}