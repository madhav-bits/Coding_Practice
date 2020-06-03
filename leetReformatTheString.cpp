/*
*
//****************************************************1417. Reformat The String.*************************************************

https://leetcode.com/problems/reformat-the-string/description/


Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. 
That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



"a0b1c2"

"aaaa1111"

"aaa1111"


"aaaa111"

"aaa1111111"

"aaaaaa"


"111111"

"a"



// Time Complexity: O(n).  													// n- length of the string.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(1).	
// This algorithm is observation based. Since, we want alternate Digit and Alpha. So, #digits and #chars shouldn't differe >1. If they
// differ>1, we return "". If Alpha are more, we start and end with char, same for digits. If Alpha are more, we give call to one func.
// which rebuilds the string starting and ending with Alpha, same for digits diff. func. is called.








class Solution {
public:
    
    string formStringChar(string s){										// Forms string with first and last char being Alphabet.
        string res="";
        int i=0, j=0;
        while(i<s.length() || j<s.length()){
            while(i<s.length() && s[i]>='0' && s[i]<='9') i++;				// Skipping all digits.
            if(i<s.length()) res+=s[i];										// Appending alphabet to result str.
            
            while(j<s.length() && s[j]>='a' && s[j]<='z') j++;				// Skipping Alphabets.
            if(j<s.length()) res+=s[j];										// Appending digits to result str.
            
            i++;j++;
        }
        return res;
    }
    
    string formStringNum(string s){											// Forms string with first and last char being Digit.
        string res="";
        int i=0, j=0;
        while(i<s.length() || j<s.length()){
            while(j<s.length() && s[j]>='a' && s[j]<='z') j++;
            if(j<s.length()) res+=s[j];
            
            while(i<s.length() && s[i]>='0' && s[i]<='9') i++;
            if(i<s.length()) res+=s[i];
            i++;j++;
        }
        return res;
    }
    
    string reformat(string s) {
        if(s.length()<=1) return s;
        int chars=0, nums=0;												// Tracks #digits and chars.
        for(auto ch:s){														// Iter. over string and cnting chars and digits.
            if(ch>='a' && ch<='z') chars++;
            else nums++;
        }
        if(abs(chars-nums)>1) return "";									// If diff.>1, return "".
        if(chars>nums) return formStringChar(s);							// If chars are more, call a func.
        else return formStringNum(s);										// If digits are more, call diff. func.
    }
};
