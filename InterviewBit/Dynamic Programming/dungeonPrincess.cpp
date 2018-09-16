/*
*
//**************************************************************Dungeon Princess.*****************************************************

https://www.interviewbit.com/problems/dungeon-princess/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3 3 -2 23 3  -5 10 1 10 30 -5




// Time Complexity: O(n*m).  
// Space Complexity: O(m).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).													
// This algorithm is Dynamic Programming based. We approach this problem from bottom to top. WE start from dest index, we set the min. req. 
// health there. Now, we iterate in the reverse drn, at each step, we calc. the min. health req. in curr. index based o next possible move's 
// min. health and curr. index's health status, we set the minm value of possible values. If the req. health after calc. is <=0 then we set 
// it to 1. After, the whole calc. we return the min. health req. at start index.







int Solution::calculateMinimumHP(vector<vector<int> > &v) {
    vector<vector<int>>dp(v.size(), vector<int>(v[0].size(),INT_MAX));		// Init. the DP array.
    dp[v.size()-1][v[0].size()-1]=1-v[v.size()-1][v[0].size()-1];			// Init. the target index values.
    if(dp[v.size()-1][v[0].size()-1]<=0) dp[v.size()-1][v[0].size()-1]=1;	// If value<=0, we set it to 1.
    for(int i=v.size()-1;i>=0;i--){											// Iter. the entire array.
        for(int j=v[0].size()-1;j>=0;j--){
            if(i==v.size()-1 && j==v[0].size()-1) continue;
            if(i+1<v.size()){												// Updating curr. index based on next row, same clmn's value.
                dp[i][j]=min(dp[i][j],dp[i+1][j]-v[i][j]);
            }
            if(j+1<v[0].size()){											// Updating curr. index based on next clmn, same row's value.
                dp[i][j]=min(dp[i][j], dp[i][j+1]-v[i][j]);
            }
            if(dp[i][j]<=0) dp[i][j]=1;										// If val. gets to <=0, we set it to 1.
        }
    }
    // for(auto nums:dp){
    //     for(auto num:nums)
    //         cout<<num<<" ";
    //     cout<<endl;
    // }
    return dp[0][0];														// Returning the minm. health req. at start index.
}











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(m).													
// This algorithm is Dynamic Programming based. We approach this problem from bottom to top. WE start from dest index, we set the min. req. 
// health there. Now, we iterate in the reverse drn, at each step, we calc. the min. health req. in curr. index based o next possible move's 
// min. health and curr. index's health status, we set the minm value of possible values. If the req. health after calc. is <=0 then we set 
// it to 1. After, the whole calc. we return the min. health req. at start index.


// This algo. is same as the above one, but is is optimized Space Complexity wise, as to update values at an index in DP array, we need values
// of prev. row.


int Solution::calculateMinimumHP(vector<vector<int> > &v) {
    vector<vector<int>>dp(2, vector<int>(v[0].size(),INT_MAX));
    
    dp[(v.size()-1)%2][v[0].size()-1]=1-v[v.size()-1][v[0].size()-1];
    if(dp[(v.size()-1)%2][v[0].size()-1]<=0) dp[(v.size()-1)%2][v[0].size()-1]=1;
    for(int i=v.size()-1;i>=0;i--){
        for(int j=v[0].size()-1;j>=0;j--){
            if(i==(v.size()-1) && j==(v[0].size()-1)) continue;
			dp[i%2][j]=INT_MAX;
            if(i+1<v.size()){
                dp[i%2][j]=min(dp[i%2][j],dp[(i+1)%2][j]-v[i][j]);
            }
            if(j+1<v[0].size()){
                dp[i%2][j]=min(dp[i%2][j], dp[i%2][j+1]-v[i][j]);
            }
            if(dp[i%2][j]<=0) dp[i%2][j]=1;
        }
    }
    // for(auto nums:dp){
    //     for(auto num:nums)
    //         cout<<num<<" ";
    //     cout<<endl;
    // }
    return dp[0][0];
}
