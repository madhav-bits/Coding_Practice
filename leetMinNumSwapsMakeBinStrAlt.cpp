/*
*
//*********************************1864. Minimum Number of Swaps to Make the Binary String Alternating.***************************************

https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"111000"
"010"
"1110"
"10101010100"
"100110010010101100"
"11011001100"
"110110001100110101000"
"0011101100"
"01"
"01100101"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. In the first iter. we calc. #ones, #zeroes, if their abs diff>1, we can't have alternate digits, so we return false.
// Based on diff, we choose starting char and count mismatches while iter. the string. In case of diff=0, start can be any char, so we first calc. mismatch,
// if the mismatches are less than half of string length, we reutrn mismatch/2, else rem.length/2 as char order would change now for othe starting char.
// We return mismatch/2, as swapping two mismatched chars is the only way these swaps would work, any other way of swapping would be redundant.







 class Solution {
public:
    int minSwaps(string s) {
        int ones=0;
        for(int i=0;i<s.length();i++) {										// Calc. diff. in occur. of ones, zeroes.
            if(s[i]=='1') ones++;
            else ones--;
        }
        if(abs(ones)>1) return -1;											// If abs diff>1, alternating strings not possible, so we return -1.
        
        char curr=(ones>=0)?'1':'0';										// If diff=-1,1 we know what would be first char, for diff=0, we try two start chars.
        int mismatch=0;
        for(char&ch:s) {													// Iter. over array and count mismatches.
            if(ch!=curr) mismatch++;
            curr=(curr=='1')?'0':'1';
        }
        if(ones!=0 || mismatch==0) return mismatch/2;						// For diff=-1,1 strings, we return #swaps needed.
        return (mismatch*2<=s.length())?mismatch/2:(s.length()-mismatch)/2;	// For diff=0, we return the best #swaps of the two possible starts.
    }
};

