/*
*
//************************************************************645. Set Mismatch.*****************************************************

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to 
another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then 
find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,3]
[1,2,2,4]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step we count the #this number has occured. If we encounter a number which have already occured. We
// note it down, we also get the sum of all numbers in the process. At the end, we substract the sum from the expected sum to get the missing num.
// If we add the repeating num to diff of expected sum and obtained sum, we get the missing number.






class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;														// Final result vec.
        vector<int>count(nums.size()+1,0);									// Tracks #occurances of nums.
        int sum=0, target=(nums.size()*(1+nums.size()))/2;;					// Sum of nums from the vector and the expected sum.
        for(auto num: nums){												// Iterating through the vector to get the sum.
            if(count[num]==1)												// If a num. occurs twice, note it down.
                res.push_back(num);
            count[num]++;													// Tracks count of nums.
            sum+=num;														// Get the sum of nums.
        }
        res.push_back(res[0]+target-sum);									// Getting the missing number.
        return res;															// Returning the result vector.
    }
};