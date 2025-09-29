/*
Ashlee Sinnerine
March 13th, 2025
Stable Marriage

You have n men and n women, and their preference rankings of each other,
and you need to match them up so that the total matching is "stable."

What is a stable matching?
A matching is stable if there are no "instabilities." 
Say the match assigns m1 to w1 and m2 to w2. An instability is the situation 
where ther is a mutal greater preference for the other person's partner than 
for one's own. For example, m1 would prefer w2 to w1 and likewise w2 prefers m1 to m2.

*/

#include <iostream>
using namespace std;

bool ok(int q[], int c){
    //men's preferences
    static int mp[3][3]= {{0,2,1},
                          {0,2,1},
                          {1,2,0}};
    
    //women's preferences              
    static int wp[3][3]= {{2,1,0},
                          {0,1,2},
                          {2,0,1}};
                          
    //checks for instability between the current pairing and past pairings
    //c=current man     q[c]=current woman
    //i=previous man    q[i]=previous woman
    for (int i=0; i<c; i++){                                        //for each previous man#i, if
        if (q[i]==q[c]                                              //woman#c is already paired with man#i
        || mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]   //man#c and man#i's partner prefer each other more
        || mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c])  //man#i and man#c's partner prefer each other more
        return false;                                               //return false
    }
    return true;
}
    

//print stable pairs
void print(int q[], int &solutionNum){
    solutionNum++;
    cout<<"Solution #"<< solutionNum << endl;
    
    cout<<"Man\tWoman\n";
    for(int i=0; i<3; i++){
        cout<< i << "\t" << q[i] <<endl;
    }
    cout<<endl;
}


int main(){
                   
    int q[3], c=0, solutionNum=0;
    
    q[0]=0;                         //create first pair
    while(c>=0){ 
        c++;                        
        if (c==3){                  //if all men are matched, print
            print(q,solutionNum);   
            c--;                    //backtrack to find another solution
        }
        else {
            q[c]=-1;               //start matching the next man
        }
         
        while (c>=0){               
        q[c]++;                     
        if (q[c] == 3) c--;         //if no woman can be matched to current man, backtrack
        else if (ok(q,c)) break;    //if woman matches current man, move to next man
        }                           
    }

    cout << "Total number of solutions: " << solutionNum << endl;
    return 0;
}