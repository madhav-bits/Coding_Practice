/*
*
//**********************************************************459. Repeated Substring Pattern.***************************************************

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You 
may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"abcabcef"

"a"


"abcdabcdabcd"


"abcdabcd"



// Time Complexity: O((n/2)#factors).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((n/2)*#factors).
// Space Complexity: O(n).	
// This algorithm is iteration based. As, we need to find substrs, which are repeated. We form substrs of length 1->n-1, at each step, we check
// whether can we form complete strs length same as that of given str. If true, then we remove first substr from the str and append it at 
// the end of str and form a new str. If both strs are equal, then we have a repeated substr.




// I had got the same idea, but I was comparing substrs starting from second till end with the first manually. Complexity wise, both are same
// this looks nicer.



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length()==1) return false;										// As, itself is substr, return false.
        for(int i=1;i<=s.length()/2;i++){									// Iterating till substr equal that of len/2.
            if(s.length()%i==0){											// If len. divides, then compare.
                string str2=s.substr(i,s.length()-i)+s.substr(0,i);			// Form new str, with first substr, removed and appended at end.
                if(str2==s) return true;									// If both strs match, return true.
            }
        }
        return false;														// If no matching strs are found, return false.
    }
};