/*
*
//************************************************************Capture Regions on Board.*****************************************************

https://www.interviewbit.com/problems/capture-regions-on-board/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4 4 XXXXXOOXXXOXXOOX


1 4 XOOX



2 4 XOOXXXXX




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is DFS based. We first iter. over edges of the given array. If we encounter 'O'  which are not visited previously, we start
// DFS from that index, along all 'O's which are direclty/indirectly connected to this index. Thus, by this step, we mark all the 'O's which
// can be reached from edges through 'O's. So, rest 'O's which are not visited after this step, are enclosed by 'X's so they can be converted to 
// 'X's, which is done in second iter. over given array.









bool maskZeroes(vector<vector<char>>&v, vector<vector<bool>>&dp, int row ,int clmn){
    dp[row][clmn]=true;														// Mark curr. index is reachable from edges.
    if(row-1>=0 && v[row-1][clmn]=='O' && dp[row-1][clmn]==false) maskZeroes(v,dp,row-1,clmn);// Travel in 4 drns to cover uncovered 'O's.
    if(clmn-1>=0 && v[row][clmn-1]=='O' && dp[row][clmn-1]==false) maskZeroes(v,dp,row,clmn-1);
    if(row+1<v.size() && v[row+1][clmn]=='O' && dp[row+1][clmn]==false) maskZeroes(v,dp,row+1,clmn);
    if(clmn+1<v[0].size() && v[row][clmn+1]=='O' && dp[row][clmn+1]==false) maskZeroes(v,dp,row,clmn+1);
    // res=maskZeroes(v,dp,row-1,clmn)
}

void Solution::solve(vector<vector<char> > &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<bool>>dp(v.size(), vector<bool>(v[0].size(),false));		// Tracks 'O's which can be reached from edges.
    for(int j=0;j<v[0].size();j++){											// Iter. over top and bottom row.
        if(v[0][j]=='O' && dp[0][j]==false) maskZeroes(v,dp,0,j);			// If  a 'O' is unvisited, start DFS from this psn.
        if(v[v.size()-1][j]=='O' && dp[v.size()-1][j]==false) maskZeroes(v,dp,v.size()-1,j);
    }
    for(int i=0;i<v.size();i++){											// Iter. over leftmost and rightmost coloumns.
        if(v[i][0]=='O' && dp[i][0]==false) maskZeroes(v,dp,i,0);
        if(v[i][v[0].size()-1]=='O' && dp[i][v[0].size()-1]==false) maskZeroes(v,dp,i,v[0].size()-1);
    }
    
    for(int i=0;i<v.size();i++){											// Iter. over given array.
        for(int j=0;j<v[0].size();j++){
            if(dp[i][j]==false && v[i][j]=='O'){							// If a 'O' isn't reachable from edges, then change it to 'X'.
                v[i][j]='X';
            }
        }
    }
    return ;
}