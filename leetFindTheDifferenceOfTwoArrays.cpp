/*
*
//******************************************************2215. Find the Difference of Two Arrays.******************************************************

https://leetcode.com/problems/find-the-difference-of-two-arrays/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[2,4,6]
[1,2,3,3]
[1,1,2,2]



// Time Complexity: O(n+l+m).												// n, l-length of two arrays, m-range of nums in the arrays.							
// Space Complexity: O(m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+l+m).												// n, l-length of two arrays, m-range of nums in the arrays.							
// Space Complexity: O(m).	
// This algorithm is Map based. We use two boolean arrays to mark the nums occurred in both arrays. We later iterate over the range of nums and add those nums
// which only occurred in first array in zero index and the ones which occurred only in second array in 1 index and return res at the end of iter.







class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        bool isPresent1[2001], isPresent2[2001];
        memset(isPresent1, false, sizeof(isPresent1));
        memset(isPresent2, false, sizeof(isPresent2));
        for(int&num:nums1) isPresent1[num+1000]=true;						// Marking that num had occurred in first array.
        for(int&num:nums2) isPresent2[num+1000]=true;						// Marking that num occurred in second array.
        vector<vector<int>>res(2);
        for(int i=0;i<=2000;i++) {											// Iter. over range of nums.
            if(isPresent1[i]==true && isPresent2[i]==false) res[0].push_back(i-1000);// If a num had occurred only in first array, we add in zero index.
            else if(isPresent1[i]==false && isPresent2[i]==true) res[1].push_back(i-1000);// If num only occurred in second array, we add in first index.
        }
        return res;															// Returning 2d array with nums which only occurred in first, second arrays resp.
    }
};

