/*
*
//******************************************************119. Pascal's Triangle II.***********************************************

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
1
2
6
4
10




// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. We iterate "K" times to get the result vector. At each step, curr. row's value depend only on
// prev. row's values, we maintain only two rows. Curr. row's index "i" depends prev. row's index "i" and index "i-1". After the end of "K"
// iterations we return the result.






class Solution {
public:
    vector<int> getRow(int k) {
        if(k==0) return vector<int>(1,1);									// If K=0, return vector with one 1.
        vector<vector<int>>dp(2,vector<int>(k+1,1));						// Init. a vector of size "k+1".
        for(int i=1;i<=k;i++){												// Iterating through "K" rows.
            // cout<<"Curr. printing row: "<<i<<endl;
            for(int j=1;j<i;j++){											// Setting values for curr. row.
                dp[i%2][j]=dp[(i-1)%2][j-1]+dp[(i-1)%2][j];					// Curr. value depends on curr. and prev. index value from prev. row.
                // cout<<"Curr. clmn: "<<j<<" with top values: "<<dp[(i-1%2)][j-1]<<" and: "<<dp[(i-1)%2][j]<<endl;
            }
        }
        
        // for(auto num:dp[k%2])
        //     cout<<num<<" ";
        return dp[k%2];														// Returing the result vector.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. We set the default value to 1, we start iterating each row from the end, we set the value at index
// "i" by adding values in that psn and prev. psn"i-1". We do this update process "K" times. After K iterations, we return the result.








class Solution {
public:
    vector<int> getRow(int k) {
        if(k==0) return vector<int>(1,1);												// If K=0, return vector with one 1.
        vector<int>dp(k+1,0);															// Init. a vector of size "k+1".
        dp[0]=1;																		// Setting first row's value to 1.
        for(int i=1;i<=k;i++){															// Setting values for "K" rows.
            // cout<<"Curr. printing row: "<<i<<endl;
            for(int j=i;j>=1;j--){														// Setting values for curr. row.
                dp[j]=dp[j]+dp[j-1];													// Curr. value depends on curr. and prev. index value.
                // cout<<"Curr. clmn: "<<j<<" with top values: "<<dp[(i-1%2)][j-1]<<" and: "<<dp[(i-1)%2][j]<<endl;
            }
        }
        
        return dp;																		// Returning the result.
    }
};






