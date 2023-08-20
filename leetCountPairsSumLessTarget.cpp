/*
*
//****************************************2824. Count Pairs Whose Sum is Less than Target.******************************************

https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-1,1,2,3,1]
2
[-6,2,5,-2,-7,-1,3]
-2
[6,5,4,3,-7,6,-3,2,2,-2,6,-4,3,8,8,-4,2,46,-0,9,8,7,-5,3,2,-3]
5




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting+Two Pointer based. Here, as we are adding two diff. nums in the array, their order doesn't matter, so sorting doesn't affect our
// final result. We sort the array, we use two pointers to iter. over array if sum of two index's values >=target, we dec. the greater ptr, else we can pair
// all the greater ptrs in the range (i, j] with v[i], as if v[i]+v[j]<target, all ptrs <j when added with v[i] would also yield total<target, we don't consider
// [0,i) as this combination is already accounted for earlier iter., now we inc. the smaller ptr. In this way we move either of the indices in every iter. and 
// return #pairs at the end of iter.







class Solution {
public:
    int countPairs(vector<int>& v, int target) {
        int res=0, i=0,j=v.size()-1;
        sort(v.begin(), v.end());
        while(i<j) {														// Using two ptrs method.
            if(v[i]+v[j]<target) {											// If sum of index pairs <target.
                res+=(j-i);													// We can pair all indices in (i,j] with v[i].
                i++;														// Moving the smaller ptr ahead.
            } else j--;														// If sum>target, we dec. the greater ptr.
        }
        return res;															// Returning the total #pairs with sum<target.
    }
};

