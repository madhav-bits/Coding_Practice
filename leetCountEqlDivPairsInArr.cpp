/*
*
//******************************************2176. Count Equal and Divisible Pairs in an Array.*******************************************

https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,1,2,2,2,1,3]
2
[1,2,3,4]
1
[3,4,5,5,4,4,6,6,6,7,7,8,7,6,6,5,4,4,3,2,2,4]
2



// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is Brute Force based. Since the length of array is small, we didn't dive deep into calc. gcd of (i,j) and iter. on mulitples of (k/gcd)>i
// indices. We iter. over every greater index for every index chosen, check for conditions, if satisfied, we count this pair towards res and return it at the 
// end of iter.







class Solution {
public:
    int countPairs(vector<int>& v, int k) {
        int res=0;
        for(int i=0;i<v.size();i++) {
            for(int j=i+1;j<v.size();j++) {									// Iter. over every greater index for every index chosen.
                if(v[j]!=v[i] || (i*j)%k!=0) continue;						// Checking for conditions specified.
                res++;														// As conditions met, count this index pair towards res.
            }
        }
        return res;															// Returning #index pairs that satisfies given conditions.
    }
};

