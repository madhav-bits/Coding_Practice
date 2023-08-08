/*
*
//******************************************************2206. Divide Array Into Equal Pairs.******************************************************

https://leetcode.com/problems/divide-array-into-equal-pairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,2,3,2,2,2]
[1,2,3,4]
[2,3,3,2,2,2,4,4]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Counting Sort based. As we are forming pairs with equal vals, each num has to occur even #times for it to be part of equal pairs. As the range of nums 
// is small, we update and track #occur of each val in occur array while iterating the array. We later iter over occur array and check if any num has occurred odd #times, we 
// return false then. Nums which would didn't occur would be having '0' in that index, which would meet our conditions. If we didn't observe any odd #occur for any num, we 
// return true.







class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int occur[501];														// Tracks #occur. of each num.
        memset(occur, 0, sizeof(occur));
        for(int&num:nums) occur[num]++;										// Updating #occur of each num in the arr.
        for(int i=0;i<=500;i++) {											
            if(occur[i]%2==1) return false;									// If any num occurred odd #times, we return false.
        }
        return true;														// Returning true as we can put each num into an equal pair.
    }
};

