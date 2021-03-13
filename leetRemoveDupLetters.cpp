/*
*
//*********************************************************316. Remove Duplicate Letters.********************************************************


https://leetcode.com/problems/remove-duplicate-letters/


Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in 
lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"bcabc"
"cbacdcbc"
"gdcgc"
"gdgc"
"gigc"
"ildibd"
"abyzazy"
"bbcaac"




// Time Complexity: O(n).  
// Space Complexity: O(1).													// As there would be 26 chars at max. in the stack.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Stack based. Here, since each char has to occur only once and the string has to be lexically small. We use stack and remove chars
// >curr. char and whose last char occurs after curr. index so that we can remove the char on top of stack without having to worry about missing that 
// char. in final string. We also keep track of chars already in the stack, so that we will skip processing those once again. We transfer chars in stack
// into string and return it.











class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res="";
        vector<int>lastOccur(26,-1);
        for(int i=0;i<s.length();i++){										// Storing indices of last occurance of each char.
            lastOccur[s[i]-'a']=i;
        }
        vector<bool>visited(26, false);										// Tracks chars in the stack.
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(visited[s[i]-'a']==false){									// Skip chars which are already in stack, so they don't affect final str.
                while(!st.empty() && st.top()>=s[i] && lastOccur[st.top()-'a']>i){// Removing chars>curr. char and last occurance >curr. index.
                    visited[st.top()-'a']=false;
                    st.pop();
                } 
                st.push(s[i]);												// Push char onto top of stack.
                visited[s[i]-'a']=true;										// Marking char as visited.
            }
        }
        while(!st.empty()){													// Transferring chars. onto string.
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;															// Returning the final string.
    }
};

