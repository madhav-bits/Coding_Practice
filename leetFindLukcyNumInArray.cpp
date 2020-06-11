/*
*
//********************************************1394. Find Lucky Integer in an Array.******************************************

https://leetcode.com/problems/find-lucky-integer-in-an-array/description/


Given an array of integers arr, a lucky integer is an integer which has a frequency in the array equal to its value.

Return a lucky integer in the array. If there are multiple lucky integers return the largest of them. If there is no lucky integer 
return -1.

 

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
Example 4:

Input: arr = [5]
Output: -1
Example 5:

Input: arr = [7,7,7,7,7,7,7]
Output: 7
 

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with examples provided with question.


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is counting based. We iter. over given array, get cnt. of #occurrences of each num. Then we iter. occcur. array from
// highest to lowest value. If we encounter any num. which is equal to #occur. we return the num. If we haven't found any such num.,
// we return -1.






class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>occur(501,0);
        for(auto num:arr) occur[num]++;										// Get count of #occur. of each num.
        int res=-1;
        for(int i=500;i>0;i--){												// Iter. over #occur. array.
            if(occur[i]==i) return i;										// If num=#occur. return num.
        }
        return -1;															// If no lucky num found, return -1.
    }
};