/*
Ashlee Sinnerine
April 28th, 2025
Non-recursive Towers of Hanoi

Using the algorithm discussed in class, write an iterative program to solve the Towers of Hanoi problem.

The problem:
You are given three towers a, b, and c. We start with n rings on tower a and we need to transfer them to tower b subject to the following restrictions:
    1. We can only move one ring at a time, and
    2. We may never put a larger numbered ring on top of a smaller numbered one.
There are always 3 towers. Your program will prompt the user for the number of rings.

The Algorithm:
    1. Find the candidate.
    2. Move the candidate (right or left, depending if the number of rings is odd or even) to the closest tower on which it can be placed. Move "around the circle" if necessary.
    3. If not done, go back to step 1.
*/

#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>t[3]; //3 Towers: A,B,C represented as 3 vectors
    int n, candidate, to, from, move=0; //move counts the move number

    cout<<"Enter the number of rings: ";
    cin>>n;

    //initialize the 3 towers
    /*  Ex: n = 3
        A   B   C
        1      
        2  
        3  
        4   4   4
    */
    for(int i=n+1; i>=1; i--){
        t[0].push_back(i); //Tower A
    }
    t[1].push_back(n+1); //Tower B
    t[2].push_back(n+1); //Tower C

    /* 
    A ring is "available" if it is on the top of one of the towers.
    The "candidate" is the smallest available ring that has not been moved on the most recent move. The first candidate is ring 1.
    */
    from=0; //starting from tower A = t[0]

    if (n % 2 == 0){ //if n is even, move to tower C = t[2]
        to=2; //to tower C
    }
    else{ //if n is odd, move to tower B = t[1]
        to=1; //to tower B
    }

    candidate=1; //the first candidate is always ring 1

    //while there are still rings to transfer to tower B = t[1]
    while(t[1].size() < n+1){ 
        cout<<"Move Number "<<++move<<": Transfer ring "<<candidate<<" from Tower "<< char(from+65)<<" to Tower "<<char(to+65)<<endl;

        t[to].push_back(t[from].back()); //move the ring from tower A to tower B/C
        t[from].pop_back(); //remove the ring from tower A

        //get next "from tower"
        if(t[(to + 1) % 3].back() < t[(to + 2) % 3].back()){
            from=(to + 1) % 3; 
        }
        else{
            from=(to + 2) % 3;
        }

        //get next "to tower"
        if(n % 2 == 0){ //if n is even, move counter-clockwise
            if (t[from].back() < t[(from + 3 - 1) % 3].back()){
                to=(from + 3 - 1) % 3;
            }
            else{
                to=(from + 3 - 2) % 3;
            }
        }
        else{ //if n is odd, move clockwise
            if (t[from].back() < t[(from + 1) % 3].back()){
                to=(from + 1) % 3;
            }
            else{
                to=(from + 2) % 3;
            }
        }

        //get next candidate
        candidate=t[from].back(); //the candidate is the top ring of the "from" tower

    }
    
    return 0;
}