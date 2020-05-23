/*

//*******************************************************A. NEKO's Maze Game.***********************************************************
https://codeforces.com/contest/1292/problem/A




Time Complexity:O(q).                                   //Q- Number of queries.                                                                                                                                                                                             
Space Complexity:O(m).                                  //Number of cols of the Maze.                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(q).                                //Q- Number of queries.                                 
// Space Complexity:O(m).                               //Number of cols of the Maze.                
// This is Array based solution. Here, we have to keep track of blocked indices of the maze. We also have to keep track of how many
// blockages had we encountered till then. If a new index is blocked, we have to scan it's adjacent indices and inc. the #blockages, 
// similary dec. the count if a index in cleared. After every moment, we check whether #blockages are "0" or not, if it is, we print
// Yes else we print No.







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






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int cols, moments;
    cin>>cols>>moments;

    // cout<<"cols; "<<cols<<" and moments: "<<moments<<endl;

    vector<vector<bool>>dp(3, vector<bool>(cols+1, true));
    int blockages=0, row=-1, col=-1;
    for(int a=0;a<moments;a++){
    	cin>>row>>col;
    	dp[row][col]=!dp[row][col];
    	if(dp[row][col]==false){
    		if(row==1 && col-1>=0 &&  dp[row+1][col-1]==false) blockages++;
    		if(row==1 && dp[row+1][col]==false) blockages++;
    		if(row==1 && col+1<=cols && dp[row+1][col+1]==false) blockages++;

    		if(row==2 && col-1>=0 && dp[row-1][col-1]==false) blockages++;
    		if(row==2 && dp[row-1][col]==false) blockages++;
    		if(row==2 && col+1<=cols && dp[row-1][col+1]==false) blockages++;
    	}else{
    		if(row==1 && col-1>=0 &&  dp[row+1][col-1]==false) blockages--;
    		if(row==1 && dp[row+1][col]==false) blockages--;
    		if(row==1 && col+1<=cols && dp[row+1][col+1]==false) blockages--;

    		if(row==2 && col-1>=0 && dp[row-1][col-1]==false) blockages--;
    		if(row==2 && dp[row-1][col]==false) blockages--;
    		if(row==2 && col+1<=cols && dp[row-1][col+1]==false) blockages--;
    	}
    	if(blockages==0) cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
    }

    return 0;
}
