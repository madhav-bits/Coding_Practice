/*
*
//**********************************************1899. Merge Triplets to Form Target Triplet.************************************************

https://leetcode.com/problems/merge-triplets-to-form-target-triplet/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[2,5,3],[1,8,4],[1,7,5]]
[2,7,5]
[[3,4,5],[4,5,6]]
[3,2,5]
[[2,5,3],[2,3,4],[1,2,5],[5,2,3]]
[5,5,5]
[[2,6,1],[5,7,3],[4,8,3],[3,2,2],[1,4,3]]
[4,7,3]
[[4,6,1],[5,7,3],[4,8,3],[3,7,2],[1,4,3]]
[4,7,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, as we can make the operations as many times as needed, we only focus on possibilitiy to acheive target array.
// We avoid using triplets which have greater vals-> triplet[i]>target[i] for any of the 3 indices of the triplet, as using this would make the resulting 
// triplet not meet the target in atleast 1 of the index. We try to track the max value for all 3 indices in remaining indices with vals<=target[i] for 3
// indices, as max vals would be the resulting vals after oper. After the iter. we return if max vals for 3 indices match the vals in target array.







class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int max1=0, max2=0, max3=0;
        for(vector<int>&v:triplets) {
            if(v[0]>target[0] || v[1]>target[1] || v[2]>target[2]) continue;// Skip indices with greater vals than target array.
            if(v[0]>max1) max1=v[0];										// Track max vals for all 3 indices, as these vals would be final result of process.
            if(v[1]>max2) max2=v[1];
            if(v[2]>max3) max3=v[2];
        }
        return (max1==target[0] && max2==target[1] && max3==target[2]);		// Returning if final/max vals match target values.
    }
};

