/*
*
//******************************************************Kth Manhattan Distance Neighbourhood.***********************************************

https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



4 5 3 5 2 5 7 2 4 7 2 19 2 6 2 2 6 3 0 19 2 5 



// Time Complexity: O(m*n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. This is a solution which gets solution as a result of multiple steps. Here, we iter. over all
// manhattan distances till target length. In every iter. while working on a index we update max. value with 'k' manhattan dist. based on max. value
// of 'k-1' manhattan distances of all it's 4 adj. indices and the same index with 'k-1' distance. This way we iter. till target dist. We return the 
// max. value of all indices with 'target' distance.




// I tried to solve it in a single iteration algorithm, but that isn't possible, as single index can be reached from various indices with diff.
// manhattan dist., we can't have a measure of max. dist to another index based on values of this index.











vector<vector<int> > Solution::solve(int target, vector<vector<int> > &v) {
    if(target==0) return v;													// Base case.
    vector<vector<vector<int>>>dp(2, vector<vector<int>>(v.size(), vector<int>(v[0].size(), 0)));	// Init. DP array.
    for(int i=0;i<v.size();i++){											// Base case of 0 manhattan dist.
        for(int j=0;j<v[0].size();j++){
            dp[0][i][j]=v[i][j];
        }
    }
    
    for(int k=1;k<=target;k++){												// Iter. over all dist. till target dist.
        for(int i=0;i<v.size();i++){										// Iter. over all indices of array.
            for(int j=0;j<v[0].size();j++){
                dp[k%2][i][j]=INT_MAX;										// Resetting dp array value.
                int up=(i-1>=0)?dp[(k-1)%2][i-1][j]:INT_MIN;				// Get max. value from 4 adj. indices with 'k-1' dist.
                int down=(i+1<v.size())?dp[(k-1)%2][i+1][j]:INT_MIN;
                int left=(j-1>=0)?dp[(k-1)%2][i][j-1]:INT_MIN;
                int right=(j+1<v[0].size())?dp[(k-1)%2][i][j+1]:INT_MIN;
                int val=max(up, down);
                val=max(val, left);
                val=max(val, right);
                dp[k%2][i][j]=max(val, dp[(k-1)%2][i][j]);					// Get max. value of adj. indices and curr. index with 'k-1' dist.
                
            }
        }
    }
    return dp[target%2];													// Retun the max. value of 'k' dist. of all indices.
}
