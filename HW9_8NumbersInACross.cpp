/*
Ashlee Sinnerine
March 10th, 2025
8 Numbers In A Cross
        __ __
     __[_][_]__
    [_][_][_][_]
       [_][_]

Write a program which allocates the integers 1-8 to the squares in the figure above,
subject ti the restrictions that no two adjacent squares contain consecutive integers.
By adjacent, we mean vertically, horizontally, or diagonally.

*/

#include <iostream>
using namespace std;

bool ok(int q[], int c){
    //helper array a - shows adjacent boxes
    // format of boxes:     0 1
    //                    2 3 4 5
    //                      6 7
    static int a[8][5] = {  {-1},               // box 0
                            {0,-1},             // box 1
                            {0,-1},             // box 2
                            {0,1,2,-1},         // box 3
                            {0,1,3,-1},         // box 4
                            {1,4,-1},           // box 5
                            {2,3,4,-1},         // box 6
                            {3,4,5,6,-1}    };  // box 7
    
    //row test
    for (int i=0; i<c; i++){
        if (q[i]==q[c]) return false;
    }
    
    //neighboring box test
    for (int i=0; a[c][i]!=-1; i++){
        if (abs(q[c]-q[a[c][i]])==1) return false;
    }
    return true;
}

//print solution
void print(int q[], int &solutionNum){
    solutionNum++;
    cout<<"Solution #"<< solutionNum << endl;
    
    cout<< "  " << q[0] << " " << q[1] << "   "<< endl;
    cout<< q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
    cout<< "  " << q[6] << " " << q[7] << "   "<< endl;
    cout<<endl;
}

int main()
{
    int q[8], c=0, solutionNum=0;   //initialize variables
    q[0]=1;                         //place first integer (1) in first box
    
    while (c>=0){                   //boxes
        c++;
        if (c==8){                  //if all boxes are filled, print solution
            print(q, solutionNum);
            c--;                    //backtrack
        }
        else{
            q[c]=0;                
        }
        while (c>=0){               //try placing integers 1-8 in current box
            q[c]++;                 //move to next integer
            if (q[c] == 9) c--;     //if no integer works, backtrack
            else if (ok(q,c)) break;//if integer works, go to next box
        }
    }
    
    cout << "Total number of solutions: " << solutionNum << endl;
    return 0;
}