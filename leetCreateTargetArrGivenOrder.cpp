/*
*
//********************************************1389. Create Target Array in the Given Order.********************************************

https://leetcode.com/problems/create-target-array-in-the-given-order/description/



Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid.

 

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
Example 2:

Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
Example 3:

Input: nums = [1], index = [0]
Output: [1]
 

Constraints:

1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[0,1,2,3,4]
[0,1,2,2,1]

[1,2,3,4,0]
[0,1,2,3,0]


[1]
[0]



// Time Complexity: O(n^2).
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is array based. We iter. over index and num array and insert vals in indices psn stored in index arr.






class Solution {
public:
    
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>res;														// Final result array.
        for(int i=0;i<nums.size();i++){										// Iter. over index and nums array.
            res.insert(res.begin()+index[i], nums[i]);						// Inserting num at index[i] psn.
        }
        return res;															// Returning the result array.
    }
};
