/*
*
//******************************************************2606. Find the Substring With Maximum Cost.******************************************************

https://leetcode.com/problems/find-the-substring-with-maximum-cost/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"adaa"
"d"
[-1000]
"abc"
"abc"
[-1,-1,-1]
"hajerlgarognoiueroiineroigvcbx"
"tebayirgjl"
[5,-2,4,8,-2,11,9,15,-9,7]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. It is very similar to Maximum of sum of Substring problem. First, we get the value of each char based on the conditions specified. We iter. over given string and keep on adding the value
// of chars to a var-total as long as the the total>=0, with the hope that the following indices would provide huge positive values and thus increasing the total value and we try to track teh max. total by comparing maxTotal
// at every index and update it if needed. If the sum of curr. substring is <=0, we stop appending chars to curr. substring as it's total<=0, and we reset the substr to zero and move to next index(thus we avoid neg. value
// contribution to the substring), thus we are greedily ensuring that we get max. substring total from the substrings formed.







class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>cost(26,0);
        for(int i=0;i<26;i++) cost[i]=i+1;																// Storing default values for all chars.
        for(int i=0;i<chars.size();i++) {																// Updating the values for the provided chars.
            cost[chars[i]-'a']=vals[i];
        }
        int res=0, total=0;																				// Track the maxSubstring total and curr. subsring total.
        for(char&ch:s) {																				// Iter. over the given string.
            total+=cost[ch-'a'];																		// Adding curr. value to curr. substring.
            if(total>res) res=total;																	// Trying to update maxSubstr total value.
            if(total<0) total=0;																		// If the substr total is <=0, we wont append curr. char and reset the substr to empty.
        }
        return res;																						// Returing the max substring total.
    }
};

