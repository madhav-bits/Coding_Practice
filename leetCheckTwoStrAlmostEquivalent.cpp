/*
*
//******************************************************2068. Check Whether Two Strings are Almost Equivalent.******************************************************

https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aaaa"
"bccb"
"abcdeef"
"abaaacc"
"cccddabba"
"babababab"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We store the freq. of chars in both strs in freq. array, we inc. the count for string1, we dec. the count for string2 to diff. the freq. of both strings, later We 
// iter. over freq. array, if for any char the diff. of freq. is >3 we return false, else we return true.









class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>occur(26,0);																			// Stores the diff. in freq. of chars in both strings.
        for(int i=0;i<word1.length();i++) {
            occur[word1[i]-'a']++;																		// Updating the freq. of chars in both strings in freq. array.
            occur[word2[i]-'a']--;
        }
        for(int i=0;i<26;i++) {
            if(abs(occur[i])>3) return false;															// Diff. in freq. of a char is>3, return false.
        }
        return true;																					// Strings are almost equivalent.
    }
};

