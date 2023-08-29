/*
*
//******************************************************2057. Smallest Index With Equal Value.******************************************************

https://leetcode.com/problems/smallest-index-with-equal-value/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1,2]
[4,3,2,1]
[1,2,3,4,5,6,7,8,9,0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. While iter. over the array, we calculate the mod value of each index and compare with value in that index, if it meets the 
// condition, we return the index as this is the first/smallest index to meet the condition. If there is no such index which meets the condition, we return -1.







class Solution {
public:
    int smallestEqual(vector<int>& v) {
        for(int i=0;i<v.size();i++) {										// Iter. over the array.
            if(i%10==v[i]) return i;										// If index meets the condition, we return the index.
        }
        return -1;															// If no index meets the condition, we return -1.
    }
};

