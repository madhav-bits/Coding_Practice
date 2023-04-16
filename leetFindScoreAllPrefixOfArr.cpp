/*
*
//******************************************************2640. Find the Score of All Prefixes of an Array.******************************************************

https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,3,7,5,10]
[1,1,2,4,8,16]
[4,2,6,2,1000000000,5,10393838,54353,2]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, while calc. scores, we keep track of max. array value till now, we use score value for prev. index and add maxm. array value+curr. value to it and 
// assign this prefixSumScore to res[i]. We return res array at end of iter.







class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& arr) {
        vector<long long int>res(arr.size(),0);															// Res array.
        int maxm=arr[0];																				// Tracks max. value.
        res[0]=2ll*arr[0];																				// Updating the first index of res array.
        for(int i=1;i<arr.size();i++) {																	// Iter. over array.
            if(arr[i]>maxm) maxm=arr[i];																// Updating the max. var.
            res[i]=arr[i]+maxm;																			// Updating the curr. res index with curr.val+maxm.
            res[i]+=res[i-1];																			// Adding prefixSumScore till prev. index to reflect prefixSumScore till curr. index.
        }
        return res;																						// Returning the prefixSumScore array.
    }
};

