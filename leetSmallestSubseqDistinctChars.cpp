/*
*
//*************************************1081. Smallest Subsequence of Distinct Characters.***********************************

Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

 

Example 1:

Input: "cdadabcc"
Output: "adbc"
Example 2:

Input: "abcd"
Output: "abcd"
Example 3:

Input: "ecbacba"
Output: "eacb"
Example 4:

Input: "leetcode"
Output: "letcod"
 

Note:

1 <= text.length <= 1000
text consists of lowercase English letters.


**********************************************************TEST CASES:******************************************************
//These are the examples I had created, tweaked and worked on.


"cdadabcc"

"leetcode"

"abcd"

"ecbacba"

"cbaacabcaaccaacababa"


// Time Complexity: O(n).  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//********************************************************Solution 1:********************************************************
//***************************************************THIS IS LEET ACCEPTED CODE.*********************************************
// Time Complexity: O(n).
// Space Complexity: O(k).	
// This algorithm is iteration based solution. Here, since we need lexically smallest uniq. char subse. We keep track of
// last occurance of each char in string. In the second iter. we iter. over given string, if curr. char is already taken,
// we ignore the curr. occurance of the char.. While adding a char. to the final string, we try to remove lexically
// greater ahead of it, which have last occurance after curr. index. In this way, we are placing lexically smallest char 
// at each psn in final str.







class Solution {
public:
    string smallestSubsequence(string s) {
        if(s.length()<=1) return s;							// Base conditions.
        string res="";
        vector<bool>taken(26, false);
        vector<int>lastOccur(26,-1);
        for(int i=0;i<s.length();i++){						// Noting the last occur. of each char.
			lastOccur[s[i]-'a']=i;
        }
        
        for(int i=0;i<s.length();i++){
            if(taken[s[i]-'a']==true) continue;
            while(!res.empty() && res.back()>s[i] && lastOccur[res.back()-'a']>i){
                taken[res.back()-'a']=false;				// Removing greater chars which occur after curr. index.
                res.pop_back();    
            } 
            res+=s[i];										// Adding curr. char to final result str.
            taken[s[i]-'a']=true;							// Marking that char is taken.
        }
        return res;											// Returning the final result str.
    }
};


