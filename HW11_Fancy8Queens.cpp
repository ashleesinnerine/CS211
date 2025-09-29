/*
Ashlee Sinnerine
April 23rd, 2025
Fancy 8 Queens

Modify the Eight Queens program (1 dimensional array – no goto version) 
so that it prints out a chessboard with some “fancy” representation of a queen 
in the appropriate positions.

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

//print a fancy chessboard with queens in the appropriate positions
void print(int q[], int &solutionNum){
    int i,j,k,l;
    typedef char box[5][7];
    box bb,wb, *board[8][8];
    
    //fill in bb=black box and wb=whitebox
    for(i=0;i<5;i++){
        for(j=0;j<7;j++){
            wb[i][j]=' ';
            bb[i][j]=char(219);
        }
    }

    //fill in wq=white queen and bq=black queen
    static box wq = {
        {' ',' ',' ',' ',' ',' ',' '},
        {' ',char(219),' ',char(219),' ',char(219),' '},
        {' ',char(219),char(219),char(219),char(219),char(219),' '},
        {' ',char(219),char(219),char(219),char(219),char(219),' '},
        {' ',' ',' ',' ',' ',' ',' '}
    };

    static box bq = {
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
        {char(219),' ',char(219),' ',char(219),' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',char(219)},
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
    };
    
    //fill board with pointers to bb and wb in alternate positions
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if((i+j)%2==0){
                board[i][j]=&wb;
            }
            else{
                board[i][j]=&bb;
            }
        }
    }
    
    //place queens in the board
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(q[i]==j){ //if the queen is in the ith row, jth column
                if((i+j)%2==0){ //if the box is white
                    board[i][j]=&wq; //place white queen in white box
                }
                else{ //if the box is black
                    board[i][j]=&bq; //place black queen in black box
                }
            }
        }
    }
    
    //print the board via the pointers in array 
    
    //increment solution number and print it
    solutionNum++;
    cout<<"Solution #"<< solutionNum << endl;

    //first print upper border
    cout<<" ";
    for(i=0;i<7*8;i++){
        cout<<char(196);
    }
    cout<<endl;
    
    //now print the board
    for(i=0;i<8;i++){ //for each board row
        for(k=0;k<5;k++){ //for each box row
            cout<<" "<<char(179); //prints left border
        
            for(j=0;j<8;j++){ //for each board column
                for(l=0;l<7;l++){ //for each box column
                    //board[i][j] is the box pointer in the ith row, jth column of the board.
                    // *board[i][j] is the box being pointed to.
                    // (*board[i][j])[k][l] is the kth row, lth column of the box.
                    cout<<(*board[i][j])[k][l]; //prints the box
                }
            }
            cout<<char(179)<<endl; //at end of line print bar and then new line
        }
    }
    
    //before exiting print lower border
    cout<<" ";
    for(i=0;i<7*8;i++){
        cout<<char(196);
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