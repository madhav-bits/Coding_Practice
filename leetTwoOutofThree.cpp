/*
*
//******************************************************2032. Two Out of Three.******************************************************

https://leetcode.com/problems/two-out-of-three/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,3,2]
[2,3]
[3]
[3,1]
[2,3]
[1,2]
[1,2,2]
[4,3,3]
[5]
[2,2]
[2,2]
[2,2]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is map based. Here, since the range of nums is limited, we use three arrays to keep track whether nums has occured in each of those arrays.
// We iter. over range of nums if a num has occured >=2 times(we get this from the tracking arrays), we add this num to res.







class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>res;
        vector<bool>occur1(101, false), occur2(101, false), occur3(101, false);// Tracks whether a num has occured in the array for each of the arrays.
        for(int&num:nums1) occur1[num]=true;								// Marking the curr. num has occured.
        for(int&num:nums2) occur2[num]=true;
        for(int&num:nums3) occur3[num]=true;
        
        for(int i=1;i<=100;i++) {
            int cnt=occur1[i]+occur2[i]+occur3[i];							// Counting #arrays curr. num has occured in.
            if(cnt>=2) res.push_back(i);									// If curr. num has occured in >=2 arrays, we add curr. num to res.
        }
        return res;															// Returning an array with nums which met the conditions.
    }
};

