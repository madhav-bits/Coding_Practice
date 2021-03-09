/*
*
//******************************************************926. Flip String to Monotone Increasing.***********************************************

https://leetcode.com/problems/flip-string-to-monotone-increasing/



A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.

 

Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
Example 3:

Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.
 

Note:

1 <= S.length <= 20000
S only consists of '0' and '1' characters.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"00110"
"010110"
"00011000"
"01010100101010101110101"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Observation/Trick based. Here, we want to ensure zeroes are followed by ones by flipping values in minimum moves. In the first iter.
// we calc. total #ones and zeroes. In the second iteration, at every step, we calc. #flips required to make it all zeroes until index 'i' and all ones
// to it's right. We remove ones to left by making #ones until now flips, remove all ones to right by removing zeroes in the right=(totalZeroes-zeroes), 
// we minimize this count over the iteration and return it at the end of iteration.










class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int totalOnes=0, totalZeroes=0;										// Stores total #ones and zeroes.
        for(char ch:s){
            if(ch=='0') totalZeroes++;
            else totalOnes++;
        }
        int ones=0, zeroes=0;
        int res=totalZeroes;
        for(char ch:s){
            if(ch=='0') zeroes++;
            else ones++;
            res=min(res, ones+totalZeroes-zeroes);							// Flips to remove ones till 'i' and zeroes after 'i' index.
        }
        return res;															// Returning the minm. flips required to acheive Monotone Inc. string.
    }
};

