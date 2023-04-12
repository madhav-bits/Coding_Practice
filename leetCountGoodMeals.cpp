/*
*
//******************************************************1711. Count Good Meals.******************************************************

https://leetcode.com/problems/count-good-meals/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,5,7,9]
[1,1,1,3,3,3,7]
[2,2,4,4,4,8,8,8,8,7,7,7,1,4,7]
[4,4,4,4,4,4]
[8,8,8,8,8,8]
[32,32,32,32,32,32,32,32,32,32]
[1048576,1048576]



// Time Complexity: O(n*k).																				//n-length of the array, k-range of deliciousness values allowed.
// Space Complexity: O(n).																				// k- can be assumed to be constant.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).																				//n-length of the array, k-range of deliciousness values allowed.
// Space Complexity: O(n).																				// k- can be assumed to be constant.
// This algorithm is Map based. Here, we iter. over given array, we store the visited values and their freq. in a map. At every index, we try to find all the powers of 2 that we can acheive with curr.
// number and the previously visited numbers. Instead of visiting all previously visited values in map, we iter. over powers of 2 and calc. the second value and check it's occur. in map, if second val.
// is present in map, we add their freq. to the res, we also update the freq. for this curr. num. Thus, we calc. all possible pairs for all possible powers of 2.







class Solution {
public:
    int countPairs(vector<int>& v) {
        int res=0, mod=1000000007, maxm=(1<<20);
        unordered_map<int,int>m;																		// Stores freq. of visited values.
        for(int&num:v) {																				// Iter. over an array.
            long int sum=1, squares=22;
            while(squares) {																			// Iter. over all possible powers of 2 sum for the provided int range.
                squares--;
                if(sum>=num && (sum-num<=maxm) && m.count(sum-num)==1) res=(0ll+res+m[sum-num])%mod;	// Check the prev. occur. of second calc. number, if present add their freq. to res.
                sum<<=1;																				// Moving to next power of 2.
            }
            m[num]++;																					// Updating the freq. of curr. num.
        }
        return res;																						// Returning the count of good meals.
    }
};

