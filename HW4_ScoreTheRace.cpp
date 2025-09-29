/*
Ashlee Sinnerine
February 13th, 2025
Score The Race

Write a program that will score a race.

Input: 
Ask the user to input a string of uppercase characters indicating the outcome of a race.

Output:
The number of teams, 
The number of runners on a team, 
The names of the teams – in alphabetical order - together with the team score,
The name and score of the winning team.

*/

#include <iostream>
using namespace std;

int main()
{
    string outcome;
    
    while (true){
        next:;
        cout << "Enter the outcome of the race in UPPERCASE (or 'DONE' to exit): \n";
        cin >> outcome;
        
        for (char &ch : outcome) { // converts input to all UPPERCASE
            ch = toupper(ch);
        }
        
        if (outcome == "DONE"){
            cout << "Thank you for playing! \n";
            return 0;
        }
        
        int teams = 0; // counts how many teams are in the race
        int teamScores[26]={0}, runnerCount[26] = {0};
        
        // processes input
        for (int i=0; i<outcome.size(); i++){
            char runner = outcome[i]; 
            int index = runner - 'A'; //convert char to index
            teamScores[index] += (i+1); // add runner's finishing place to total team score
            runnerCount[index]++; // increase number of runners for team
        }
        
        // counts number of teams
        for (int i=0; i<26;i++){ 
            if (runnerCount[i] > 0) {
                teams++;
            }
        }
        
        // checks if all teams have the same num of runners
        int firstRunnerCount = runnerCount[outcome[0] - 'A'];
        
        for (int i=0; i<26;i++){
            if (runnerCount[i] > 0 && runnerCount[i] != firstRunnerCount){
                cout << "The teams do not have the same number of runners. Please enter a valid outcome." << endl;
                goto next;
            }
        }
        
        // print results
        cout << "There are " << teams << " teams.\n";
        cout << "Each team has " << firstRunnerCount << " runners.\n";
        cout << "Team   Score\n";
        
        // calculate and print team scores
        double winningScore = (double)teamScores[outcome[0] - 'A'] / firstRunnerCount;
        char winningTeam = outcome[0];
        
        for (int i=0;i<26;i++){
            if (runnerCount[i] > 0) {
                double average = (double)teamScores[i] / firstRunnerCount;
                cout << "  " << (char)(i + 'A') << "    " << average << endl;
                if (average < winningScore){
                    winningScore = average;
                    winningTeam = (char)(i +'A');
                }
            }
        }
        
        cout << "The winning team is team " << winningTeam << " with a score of " << winningScore << ".\n";
    }
    return 0;
}