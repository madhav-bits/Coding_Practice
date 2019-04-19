/*

//****************************************************ADAGAME - Ada and Game.********************************************************
https://www.spoj.com/problems/ADAGAME/




// Time Complexity:O(n*m).                                                     // n-range of allowed vals, m-#moves allowed.                                                  
// Space Complexity:O(n*m).                                                    // In Bottom-Top Approach, we can reduce to O(n).                                               

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n*m).                                                     // n-range of allowed vals, m-#moves allowed.                                                  
// Space Complexity:O(n*m).                                                    // In Bottom-Top Approach, we can reduce to O(n).                                                   
// This is Dynamic Programming/Hashing based solution. Here, we start from the given start value, we iter. over 4 possibilities 
// until all moves are exhausted. If after making last move, if the value>start value, we mark that person who marked last but one
// has won, in case of odd moves, Ada makes last move, if we greater value atlast, then Ada won, so, if we have odd moves, then we
// assign last person/move/Ada has won, if any move in last step leads to greater value for next step. 
// All other moves are considered normally, if any move leads to next person losing, we assign curr. number as winning.
// At the end of entire process, we return the state of 0 moves, start value.


// dp[move][number]=0;  indicates that at the curr. move the given number is losing.
// dp[move][number]=1;  indicates that at the curr. move the given number is winning.







#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;




int makeMoves(int move, int number, vector<vector<int>>&dp, int moves, int start){
    if(dp[move][number]!=-1) return dp[move][number];
    if(move==moves){
        if(number>start) dp[move][number]=1;    // Ada Won.
        else dp[move][number]=0;
        return dp[move][number];
    }


    string s=to_string(number);
    while(s.length()<4) s="0"+s;
    string t=s;
    for(int k=0;k<4;k++){
        t=s;
        t[k]++;
        if(t[k]==58) t[k]='0';
        int num=stoi(t);
        // cout<<"modified number: "<<numb<<endl;
        makeMoves(move+1, num, dp, moves, start);
        if(moves%2==1 && move==moves-1 ){                                   // Main logic lies here, in case of odd #moves, final state, last move belongs to Ada. 
            if(dp[move+1][num]==true) dp[move][number]=1;
        } 
        else if(dp[move+1][num]==false) dp[move][number]=1;                 // This is normal change of turns.
    }

    if(dp[move][number]==-1) dp[move][number]=0;                            
    return dp[move][number];

}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, start, moves;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>start>>moves;
        // cout<<"Start: "<<start<<" and moves: "<<moves<<endl;

        // vector<vector<bool>>dp(moves+1, vector<bool>(10000, false));     // Commented part is Bottom-Top Approach.
        // for(int j=start+1;moves>=0 && j<10000;j++) dp[moves][j]=true;    // It's giving TLE errors as many unwanted states are visited.

        // for(int i=moves-1;i>=0;i--){
        //     for(int j=0;j<10000;j++){
        //         // cout<<"curr. num: "<<j<<endl;
        //         string s=to_string(j);
        //         while(s.length()<4) s="0"+s;
        //         string t=s;
        //         for(int k=0;k<4;k++){
        //             t=s;
        //             // char ch=t[k];
        //             // ch++;
        //             t[k]++;
        //             if(t[k]==58) t[k]='0';
        //             int num=stoi(t);
        //             // cout<<"modified number: "<<numb<<endl;
        //             if(moves%2==1 && i==moves-1 ){
        //                 if(dp[i+1][num]==true) dp[i][j]=true;
        //             } 
        //             else if(dp[i+1][num]==false) dp[i][j]=true;
        //         }
        //     }
        // }

        // if(dp[0][start]==true) cout<<"Ada"<<endl;
        // else cout<<"Vinit"<<endl;

        vector<vector<int>>dp(moves+1, vector<int>(10000, -1));
        makeMoves(0, start, dp, moves, start);
        if(dp[0][start]==1) cout<<"Ada"<<endl;
        else cout<<"Vinit"<<endl;
    }

    return 0;
}
