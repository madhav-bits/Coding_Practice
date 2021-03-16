/*
*
//********************************************1780. Check if Number is a Sum of Powers of Three.***********************************************

https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/


Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
Example 3:

Input: n = 21
Output: false
 

Constraints:

1 <= n <= 107



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



300
18
2
1
20
21
90
244



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Greedy based. We first collect all powers of 3 <=10000000. We iter. from greater to smaller powers of 3, when we encounter a val
// <=target value, we subtract the power from the target value and fill the remaining value with the remaining powers. We greedily pick this power as 
// the sum of all lesser powers is<curr. power, so their total won't match given target. We will stop iteration once the target value is 0 or finished
// iteration.









class Solution {
public:
    bool checkPowersOfThree(int n) {
        int num=1;
        vector<int>powers;
        while(num<=10000000){
            powers.push_back(num);											// Collecting powers<=10000000.
            num*=3;
        }
        int i=powers.size()-1;									
        while(i>=0 && n){													// Iter. from greater to lower powers.
            if(powers[i]<=n) n-=powers[i];									// If curr. power value<=required target,we substract curr. power value.
            i--;															// Moving to lower power value to check.
        }
        return (n==0);														// Checking whether target value had been reached or not.
    }
};

