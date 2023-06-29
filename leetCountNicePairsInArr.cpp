/*
*
//******************************************************1814. Count Nice Pairs in an Array.******************************************************

https://leetcode.com/problems/count-nice-pairs-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[42,11,1,97]
[13,10,35,24,76]
[5,12,15,23,26,19,24,28,34,30,25,16,15,18,42,47,49]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. The provided condition can be slightly modified into a form where we are trying to get same diff (u[i]-rev(u[i])) b/w diff. pairs. While 
// iter. we calc. this diff for every index and check in map for any prev. occurances of same diff, if yes we add #times such diff. occured in the past as all of them forms
// pairs with curr. index and we inc. the count of curr. diff in map by 1. We return total #pairs formed at the end of iter.






class Solution {
public:
    
    int getReverse(int num) {												// Calc. the reverse of provided number.
        int res=0;
        while(num>0) {
            res=res*10+num%10;
            num/=10;
        }
        return res;
    }
    
    int countNicePairs(vector<int>& nums) {
        int res=0, mod=1000000007;
        unordered_map<int,int>m;
        for(int num:nums) {
            int rev=getReverse(num);										// Get reverse of curr. number.
            if(m.count(num-rev)==1) res=(res+m[num-rev])%mod;				// Adding all prev. occur. of same diff to res as all of them will form pairs with curr. diff.
            // cout<<"diff: "<<num-rev<<endl;
            m[num-rev]++;													// Adding curr. diff's occurance to map.
        }
        
        return res;															// Returning the total #pairs.
    }
};
