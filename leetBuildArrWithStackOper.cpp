/*
*
//**********************************************1441. Build an Array With Stack Operations.******************************************

https://leetcode.com/problems/build-an-array-with-stack-operations/description/


Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.

Build the target array using the following operations:

Push: Read a new element from the beginning list, and push it in the array.
Pop: delete the last element of the array.
If the target array is already built, stop reading more elements.
You are guaranteed that the target array is strictly increasing, only containing numbers between 1 to n inclusive.

Return the operations to build the target array.

You are guaranteed that the answer is unique.

 

Example 1:

Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]
Example 2:

Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
Example 3:

Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.
Example 4:

Input: target = [2,3,4], n = 4
Output: ["Push","Pop","Push","Push","Push"]
 

Constraints:

1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target is strictly increasing.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



Worked with the provided test cases.


// Time Complexity: O(n).  													// n- #numbers in the list.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #numbers in the list.
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we read nums from 1 to n. We have a target array with specific nums, we put pointers on 
// list and target array.If curr. read number from list matches curr. target array number we take it, if not we "Pop" it after reading.
// Once, we read all nums in target array, we stop.






class Solution {
public:
    vector<string> buildArray(vector<int>& v, int n) {
        int index=0, i=1;													// Pointers on target array and list of nums.
        vector<string>res;													// Stores all operations to form target array.
        while(index<v.size()){												// Form target array.
            res.push_back("Push");											// Read from list of nums.
            if(i!=v[index]) res.push_back("Pop");							// If curr. num from list doesn't match with target, Pop it.
            else index++;													// If matches, inc. the target array index.
            i++;															// Inc. the next reading value.
        }
        return res;															// Return the final list of operations.
    }
};