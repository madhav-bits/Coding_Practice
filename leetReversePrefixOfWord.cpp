/*
*
//******************************************************2000. Reverse Prefix of Word.******************************************************

https://leetcode.com/problems/reverse-prefix-of-word/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcdefd"
"d"
"xyxzxe"
"z"
"abcd"
"z"
"abcdebdab"
"d"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we iter. and find the first occur. of the target char, then reverse the substring/prefix of the string until that index. If we dont find the target char in the string, we return
// the orig. string else we return the modified string.







class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.length()<=1) return word;																// Base case.
        int i=0, j=0;
        while(j<word.length() && word[j]!=ch) j++;														// Finding the first occur. of the target char.
        if(j==word.length()) return word;																// If target char not found, return orig. string.
        while(i<j) {																					// Reversing the substring/prefix until the first occur. of target char.
            swap(word[i], word[j]);
            i++;
            j--;
        }
        return word;																					// Returning the modified string.
    }
};

