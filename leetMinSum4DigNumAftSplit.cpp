/*
*
//********************************************2160. Minimum Sum of Four Digit Number After Splitting Digits.***************************************

https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2932
4009
8383
8583
1234
2021
1001
1100
9990
9901
7654
9900




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).	
// Space Complexity: O(1).	
// This algorithm is Sorting+Greedy based. We first stringify the given num and sort it based on digits. For us to get min. sum of digits we have to split it into 2,2 digits each.
// Also least value digits have to take 10s digit psn, so that their total remains least, we acheive this by swapping s[1], s[2] and forming nums by modified str and return their
// total.







class Solution {
public:
    int minimumSum(int num) {
        string s=to_string(num);											// Stringify given num.
        sort(s.begin(), s.end());											// Sort the given digits.
        swap(s[1], s[2]);													// Swap second, third smallest digits.
        int num1=stoi(s.substr(0,2)), num2=stoi(s.substr(2,2));				// Forming two digits after modifying string.
        return num1+num2;													// Returning the sum of split nums.
    }
};

