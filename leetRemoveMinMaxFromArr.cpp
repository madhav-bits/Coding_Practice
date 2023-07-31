/*
*
//***********************************************2091. Removing Minimum and Maximum From Array.**********************************************

https://leetcode.com/problems/removing-minimum-and-maximum-from-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,10,7,5,4,1,8,6]
[0,-4,19,1,8,-2,-3,5]
[2,10,7,5,1,4,8,6]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We first iterate over array and track indice of min, max values in the array. We compare and swap indices so that maxIndex indicates the 
// least index of the two, similarly for minIndex too. There are three ways to delete the 2 indices, 1 way is to delete form the left until the maxIndex, other way is to 
// delete values from right until the minIndex, other way is to delete the minIndex from left and maxIndex from right, we calc. #deletions needed for each of the 3 ways and 
// return the min #moves.







class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex=0, maxIndex=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<nums[minIndex]) minIndex=i;							// Tracking the index for the min. value in the array.
            if(nums[i]>nums[maxIndex]) maxIndex=i;							// Tracking the index for the max. value in the array.
            
            
        }
        if(minIndex>maxIndex) swap(minIndex, maxIndex);						// Swapping so that minIndex represents the min value, maxIndex represents max value of the two.
        int res=min(maxIndex+1, 0+(int)nums.size()-minIndex);				// Tracking min. moves among the 2 ways to delete 2 indices from the back and the front.
        if(minIndex+1+nums.size()-maxIndex<res) res=minIndex+1+nums.size()-maxIndex;// If #moves to delete from both ends is smaller, we updated min #moves with it.
        return res;															// Returning the minm. #moves to delete min, max value in the array.
    }
};


