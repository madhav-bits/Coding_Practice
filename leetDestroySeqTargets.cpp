/*
*
//******************************************************2453. Destroy Sequential Targets.******************************************************

https://leetcode.com/problems/destroy-sequential-targets/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,7,8,1,1,5]
2
[1,3,5,2,4,6]
2
[6,2,5]
100
[5,7,6,8,8,9,10,14,18,22,1]
2
[625879766,235326233,250224393,501422042,683823101,948619719,680305710,733191937,182186779,353350082]
4



// Time Complexity: O(n).																				// n-length of the nums array, m-diff number.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n-length of the nums array, m-diff number.
// Space Complexity: O(m).	
// This algorithm is Map based. Here, there is an observation that for all the nums to be destroyed by a same base number, there %values(num%diff) have to be same, where the least of those nums would serve as the base number. 
// As they have same % value, we can be certain that there diff will be in multiples of diff from the base number. So, we iter. over all nums and track the #nums with same % value, we track the max. #nums with same %value.
// We iter. over array once again and get the least valued number with the max rep. %value and return it.







class Solution {
public:
    int destroyTargets(vector<int>& nums, int diff) {
        unordered_map<int,int>m;
        int res=INT_MAX, maxLen=1;
        for(int&num:nums) {
            int rem=num%diff;
            m[rem]++;																					// Updating the #ocur. of calc. %value.
            if(m[rem]>=maxLen) maxLen=m[rem];															// Tracking the max. #rep of %value.
        }
        for(int&num:nums) {
            if(m[num%diff]==maxLen) res=min(res, num);													// Getting the least num with same #rep as max rep. 
        }
        return res;																						// Returing the least valued number which can destroy max. #targets.
    }
};

