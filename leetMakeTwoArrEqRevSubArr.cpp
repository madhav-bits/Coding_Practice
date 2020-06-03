/*
*
//***************************************1460. Make Two Arrays Equal by Reversing Sub-arrays.******************************************

https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/description/


Given two integer arrays of equal length target and arr.

In one step, you can select any non-empty sub-array of arr and reverse it. You are allowed to make any number of steps.

Return True if you can make arr equal to target, or False otherwise.

 

Example 1:

Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse sub-array [2,4,1], arr becomes [1,4,2,3]
2- Reverse sub-array [4,2], arr becomes [1,2,4,3]
3- Reverse sub-array [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
Example 2:

Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
Example 3:

Input: target = [1,12], arr = [12,1]
Output: true
Example 4:

Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr doesn't have value 9 and it can never be converted to target.
Example 5:

Input: target = [1,1,1,1,1], arr = [1,1,1,1,1]
Output: true
 

Constraints:

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4]
[2,4,1,3]


[3,7,9]
[3,7,11]


// Time Complexity: O(n+m).  												// m,n length of the two arrays.
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// m,n length of the two arrays.											
// Space Complexity: O(k).	
// This algorithm is observation based. Here, we can use the swap method to bring to a desired val. to it's target index. We first set
// the zero index and go in inc. order. So, we would be able to form target str, if given str has same #each num from target str.








class Solution {
public:
    bool canBeEqual(vector<int>& s, vector<int>& t) {
        vector<int>occur1(1000,0), occur2(1000,0);							// Stores cnt. of each num of two strings.
        for(int num:s) occur1[num-1]++;										// Counting #occur. of each num in string 1.
        for(int num:t) occur2[num-1]++;										// Counting #occur. of each num in string 2.
        for(int i=0;i<1000;i++){											// Comparing #occur. of all possible nums in two strs.
            if(occur1[i]!=occur2[i]) return false;							// If #occur. doesn't match, target can't be formed return false.
        }
        return true;														// All the nums occur. matched, return true.
    }
};
