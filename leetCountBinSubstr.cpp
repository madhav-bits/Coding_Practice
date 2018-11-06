/*
*
//******************************************************696. Count Binary Substrings.***********************************************

Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 
1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"0"


"0100101011"


"00010101001"


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. As, we have to focus on consecutive zeros and ones, we iterate over given string, as cosecutive zeros and
// ones with same count is required, we take the min. of the two count and add it to final count. We add it to final count, when a new char !=
// prev. char has occured. At the end of iteration, we also add the contribution of last pair of conse. zeros and ones to the final count.







class Solution {
public:
    int countBinarySubstrings(string s) {
        int ones=0, zeros=0;
        int i=1;
        if(s[0]=='0') zeros=1;												// Init. tracker values based on first value.
        else ones=1;
        int res=0;															// Final result.
        for(;i<s.length();i++){												// Iter. over all chars.
            // cout<<"index: "<<i<<" ones: "<<ones<<" and zeros: "<<zeros<<endl;
            if(s[i]!=s[i-1]){												// If new char is observed.
                res+=min(zeros,ones);										// Add min. of two to final count.
                if(s[i]=='0') zeros=1;										// Set the count for sequence starting curr. index.
                else ones=1;
            }else{															// If curr. char is same as prev. char.
                if(s[i]=='0') zeros+=1;										// Inc. the count value.
                else ones+=1;
            }
        }
        res+=min(ones, zeros);												// Add the contribution of last pair of conse. ones and zeros.
        return res;															// Return the total count.
    }
};