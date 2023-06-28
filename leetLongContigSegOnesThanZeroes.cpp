/*
*
//******************************************************1869. Longer Contiguous Segments of Ones than Zeros.******************************************************

https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"1101"
"111000"
"110100010"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, in every step of iter. we inc. the count of length of curr. subarray of zeroes/ones accordingly. We also try to maximize the 
// length of the longest subarray of zeroes/ones. We return if longest subarray of ones is lengthier than that of zeroes at the end of iter.







class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOnes=0, maxZeroes=0;
        int ones=0, zeroes=0;
        for(char&ch:s){
            if(ch=='0') zeroes++, ones=0;									// Inc. the curr. zeroes subarray length and resetting the ones subarray length to zero.
            else ones++, zeroes=0;
            if(zeroes>maxZeroes) maxZeroes=zeroes;							// Maximizing the longest zeroes subarray length.
            if(ones>maxOnes) maxOnes=ones;
        }
        return (maxOnes>maxZeroes);											// Returning if longest ones subarray length is > zeroes subarray length.
    }
};
