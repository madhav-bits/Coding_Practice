/*
*
//**********************************************************724. Find Pivot Index.***************************************************

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers 
to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].


//These are the examples I had created, tweaked and worked on.
[1,3,2,5,3,7,3,7,8,4,7,7,9,4,3,2,3]
[]


// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This algorithm differentiates the sum to the left and sum to the right and saves them in two different variables and the moment the values
// are equal it's return the corresonding index.

class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int sum=0;
        for(auto num:v)									// Calc. the sum of all elements.
            sum+=num;
        int sum1=0, sum2=sum;							// In the beginning as all elem. are to the right. So, num2 equal sum of all elem.
        for(int i=0;i<v.size();i++){
            sum2-=v[i];									// While scanning elem. at index-"i", sub. value at index-"i".
            if(sum1==sum2)
                return i;
            sum1+=v[i];									// Adding this value to sum1, as this value will be left of elem.at index-"i+1".
        }
        return -1;										// If no such index exists, returning -1.
    }
};