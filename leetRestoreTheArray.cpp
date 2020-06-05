/*
*
//***************************************************1416. Restore The Array.***************************************************

https://leetcode.com/problems/restore-the-array/description/


A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of 
digits and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k. There can be multiple ways to restore the array.

Return the number of possible array that can be printed as a string s using the mentioned program.

The number of ways could be very large so return it modulo 10^9 + 7

 

Example 1:

Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]
Example 2:

Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
Example 3:

Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
Example 4:

Input: s = "2020", k = 30
Output: 1
Explanation: The only possible array is [20,20]. [2020] is invalid because 2020 > 30. [2,020] is ivalid because 020 contains leading 
zeros.
Example 5:

Input: s = "1234567890", k = 90
Output: 34
 

Constraints:

1 <= s.length <= 10^5.
s consists of only digits and doesn't contain leading zeros.
1 <= k <= 10^9.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"1000"
10000


"1000"
10


"1317"
2000


"2020"
30


"1234567890"
90


"600342244431311113256628376226052681059918526204"
703





// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, there are many nums. that can be formed starting at an index, so we have to cnt.
// all the nums. that can be formed starting from next index of curr. num's ending and add all possible num's endings starting from curr.
// index to get all possible nums. from curr. index. 








class Solution {
public:
    
    int formNumber(string &s, int index, int cap, vector<int>&dp){
        if(index>=s.length()) return 1;										// Out of index bounds.
        if(s[index]=='0') return 0;											// As, num. can't start with leading zeroes, return 0.
        if(dp[index]!=-1) return dp[index];									// If #ways already calc. return the cnt.
        int total=0, i=index;   //, mod=1000000007;							// Tracks #ways starting curr. index and iter. index.
        long long int currVal=0;											// Tracking curr. num.
        while(i<s.length()){												// Iter. until we would be able to form nums.
            currVal=currVal*10+(s[i++]-'0');
            if(currVal>cap) break;											// If curr. num>cap that we can form then stop iter.
            total+=formNumber(s,i, cap, dp);								// Get #ways from rest of the indices and add to curr. cnt.
            total%=1000000007;
        }
        return dp[index]=total;												// Assign the total cnt. to dp index and return the val.
    }
    
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.length(),-1);										// Init. the DP array.
        // int dp[s.length()];
        // for(int i=0;i<s.length();i++)
        //     dp[i]=-1;
        formNumber(s,0,k, dp);												// Give the func. call to DP recursion.
        // for(int i=0;i<s.length();i++)
        //     cout<<"i: "<<i<<" and dp: "<<dp[i]<<endl;
        return dp[0];														// Return all possible ways starting index zero.
    }
};
