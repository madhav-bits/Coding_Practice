/*
*
//**********************************************************1763. Longest Nice Substring.***************************************************

https://leetcode.com/problems/longest-nice-substring/



A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice 
because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there 
are none, return an empty string.

 

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.
Example 4:

Input: s = "dDzeE"
Output: "dD"
Explanation: Both "dD" and "eE" are the longest nice substrings.
As there are multiple longest nice substrings, return "dD" since it occurs earlier.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"YazaAay"
"ZbxczCdD"
"ZbxczCzdzD"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Divide and Conquer based. Here, in every iteration, we divide the string by the index of first char which don't have both cases 
// present and recursively call function on both the parts, in the worst case we split the string 26 times and in every part we might iterate over entire
// string, our time complexity is (n*26).


// This link gives some explanation for this approach.
// https://leetcode.com/problems/longest-nice-substring/discuss/1074589/JavaStraightforward-Divide-and-Conquer





class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.length()<=1)  return "";
        vector<bool>lower(26,false),upper(26,false);
        for(char ch:s){														// Noting down whether both cases chars had occured or not.
            if(ch>='a') lower[ch-'a']=true;
            if(ch<='Z') upper[ch-'A']=true;
        }
        for(int i=0;i<s.length();i++){
            if(lower[tolower(s[i])-'a'] ^ upper[toupper(s[i])-'A']){		// Split string by the first char which don't have both cases present in string.
                string u=longestNiceSubstring(s.substr(0,i));				// Recursively call fn on both the parts.
                string t=longestNiceSubstring(s.substr(i+1));
                // cout<<"s: "<<u<<" and t: "<<t<<endl;
                return (u.length()>=t.length())?u:t;						// Return the longest string from the call.
            }
        }
        return s;															// Returing the longest Nice Substring.
    }
};

