/*
Ashlee Sinnerine
February 24th, 2025
8 Queens 2D Array

Complete the 8 Queens 2-Dimensional Array Program with backtracking
(i.e. print the board) that we worked on in class.

*/

#include <iostream>
using namespace std;

int main(){
    int b[8][8]={0},row,col=0,solutionNum=0;
    
    //put the queen in the upper left square
    b[0][0]=1;
    
    nextCol:
        col++;
        if (col==8) goto print;
        row=-1;
    
    nextRow:
        row++;
        if (row==8) goto backtrack;
        
        //row test
        for (int i=0;i<col;i++){
            if (b[row][i]==1) goto nextRow;
        }
        
        //up diagonal test
        for (int i=1; (row-i)>-1 && (col-i)>-1; i++){
            if (b[row-i][col-i]==1) goto nextRow;
        }
        
        //down diagonal test
        for (int i=1; (row+i)<8 && (col-i)>-1; i++){
            if (b[row+i][col-i]==1) goto nextRow;
        }
        
        //place the queen
        b[row][col]=1;
        goto nextCol;
    
    backtrack:  
        col--;
        if (col==-1){
            cout<<"Total number of solutions: "<<solutionNum<<endl;
            return 0;
        }
        
        //find the queen
        row=0;
        while(b[row][col]!=1){
            row++;
        }
        b[row][col]=0;
        goto nextRow;
        
    print:  
        solutionNum++;
        cout<<"Solution #"<< solutionNum << endl;
        
        //print chessboard
        for (int r=0;r<8;r++){
            for (int c=0;c<8;c++){
                cout<<b[r][c]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        goto backtrack;
    

    return 0;
}