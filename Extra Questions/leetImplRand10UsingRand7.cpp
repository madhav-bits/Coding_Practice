/*
*
//******************************************************872. Implement Rand10() Using Rand7().***********************************************

Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform 
random integer in the range 1 to 10.

Do NOT use system's Math.random().

 

Example 1:

Input: 1
Output: [7]
Example 2:

Input: 2
Output: [8,4]
Example 3:

Input: 3
Output: [8,1,10]
 

Note:

rand7 is predefined.
Each testcase has one argument: n, the number of times that rand10 is called.
 

Follow up:

What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
3
10
10000



// Time Complexity: O(1).													// Geometric series sum leads to Ammortized Complexity.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Geometric series sum leads to Ammortized Complexity.
// Space Complexity: O(1).	
// This algorithm is Standard Math based. We come up with a rand generator base value>target value, using given base7() fn. We later iterate
// in the till we get a value<largest multiple of target base less then bigger base value. Such, that the range (0,mult. of target base-1) are 
// evenly distributed across the range of target rand outputs.



// Here, we use this formula N ^ b * (randN() - 1) + N ^ (b - 1) * (randN() - 1) + N ^ (b - 2) * (randN() - 1) + ... + N ^ 0 * (randN() - 1) generates randX() - 1, where X = N ^ (b + 1).
// to get rand49()-1, then we exit loop, if values are 0 to 39, now divide with 10 to get uniform distribution of values from 1 to 10.


// There, are real clear explanations in the discussion forum of this question.








// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int res=40;
        while(res>=40) res=(7*(rand7()-1)+rand7()-1);						// Creating a rand 49()-1. Extract rand40()-1.
        return (res%10)+1;													// Convert it into target rand values.
    }
};