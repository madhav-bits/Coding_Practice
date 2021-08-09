/*
*
//**************************************1509. Minimum Difference Between Largest and Smallest Value in Three Moves.***************************************

https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/submissions/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[5,3,2,4]
[1,5,0,10,14]
[6,6,0,1,1,4,6]
[1,5,6,14,15]



// Time Complexity: O(nlogn).  												// n-#length of the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n-#length of the array.
// Space Complexity: O(1).	
// This algorithm is Sorting based. Here, as we want smallest diff after three deletions. Their are 4 possible outputs after deleting three nums.
// We sort the given array so that we can delete the nums on both ends so that the diff becomes less in value. We iter. over 4 possible situations and 
// return the min. diff b/w nums on both ends(Smallest, Largest values). As 3 deletions would dec. the diff. we make 3 deletions.











class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;										// Base cases.
        sort(nums.begin(), nums.end());										// Sorting the array.
        int low=3, high=(int)nums.size()-1;									// Pointers to both ends of the array after deletions.
        int res=nums[high]-nums[low];										// Calc. diff. for one possible combination(All deletions are on left side).
        while(low>0){														// Iter. over three other possible situations.
            low--;
            high--;
            res=min(res, nums[high]-nums[low]);								// Tracking min. diff among all possibilities.
        }
        return res;															// Returning the min. possible diff b/w min, max values after deletions.
    }
};
