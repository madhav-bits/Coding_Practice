/*
*
//**************************************************************312. Burst Balloons.*******************************************************

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all 
the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of 
i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,5,8]
[]
[4,1,1,0,1]




// Time Complexity: O(n^3).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. We approach it from bottom to top. We iterate a substring, and take all the middle indices as 
// last balloons to be poped and calc. the max. value that can be extracted from that substring. This way, we keep on inc. the sbustring length
// until the substring gets equal to main string. We approach from the bottom and last balloon to be bursted, and extract the max. possible sum
// and store it in the DP array for the substring. After entire iteration, we return value for dp[0][len-1].








class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> val;
        val.push_back(1);																		// Padding with 1's on both ends.
        for(auto a: nums) if(a>0) val.push_back(a);												// Rem. balloons with zero value.
        val.push_back(1);
        //cout<<"The val. size is: "<<val.size()<<endl;
        vector<vector<int>>dp(val.size(), vector<int>(val.size(),0));
        for(int len=2;len<val.size();len++){            										// Diff. b/w (last-start) indices(len of substr-1).
            for(int start=0;start+len<val.size();start++){										// Start index of substr.
                int end= start+len;																// End index of substr.
                for(int last=start+1;last<end;last++){											// The last balloon we assume to be popped.
                    int sum=(val[start]* val[last]* val[end])+dp[start][last]+dp[last][end];
                    //cout<<"start: "<<start<<" end: "<<end<<" last: "<<last<< "calc. val: "<<sum<<endl;
                    dp[start][end]=max(dp[start][end], sum);									// Extracting the max. sum.
                }
            }
        }
        //cout<<"The result is: "<<dp[0][dp.size()-1]<<endl;
        return dp[0][dp.size()-1];																// We return the max. sum obatined from the vector.
    }
};