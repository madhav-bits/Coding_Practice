/*
*
//******************************************************2110. Number of Smooth Descent Periods of a Stock.******************************************************

https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,2,1,4]
[8,6,7,7]
[1]
[2,2,2,2,2,2]
[4,4,4,3,3,3,2,2,2,2,1,1,1,1,5,4,3,27,6,5,6,8,5,4,3,8,5,3,7,8,9,8,7,6,7,6,5,4,6]
[8,7,6,5,4,3,2,2,2,1,1,3,2,1,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since a single index is also considered as a desc. period. While iterating we compare every num with it's prev. num, if this is 1 less than prev. num,
// then curr. num would be part of curr. descent period till the last index, since the curr. num can form a descent period starting every index in the curr. descent window, we add the curr. descent
// period/window length to the res. If curr. num can't be part of curr. descent period, we start a new one now and we add 1 to res. Thus, at every index we check if curr. num can be included in the 
// curr. descent window or not and add the number of descent periods ending with curr. index to res. We return final res at the end of iter.







class Solution {
public:
    long long getDescentPeriods(vector<int>& v) {
        long long int res=1, cnt=1;																		// Default values for index-0.
        for(int i=1;i<v.size();i++) {																	// Iter. over curr. array.
            if(v[i]==v[i-1]-1) cnt++;																	// If curr. num is part of curr. descent period, we inc. the length by 1.
            else cnt=1;																					// We reset the descent period length to 1.
            res+=cnt;																					// Adding the count/number of descent periods ending at curr. index.
        }
        return res;																						// Returning the final count of descent periods.
    }
};

