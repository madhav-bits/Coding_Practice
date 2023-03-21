/*
*
//******************************************************1935. Maximum Number of Words You Can Type.******************************************************

https://leetcode.com/problems/maximum-number-of-words-you-can-type/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"hello world"
"ad"
"leet code"
"lt"
"leet code"
"e"
"aaaa bbb"
"a"
"aaaa bbb a"
"a"
"aaaa bb b"
"a"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We store all broken chars in an array to track easily. Later we iter. over the given string, whenver we encounter ' ' char, this means prev. word is finished, we
// check for #broken chars in prev. word in valid variable, it is true if no broken chars are found in prev. word. If broken chars not found, we inc. the fully typable words count and return it end 
// of iter.






class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool>broken(26, false);																	// Tracks all broken chars.
        for(char&ch:brokenLetters) {
            broken[ch-'a']=true;																		// Stores all broken chars.
        }
        int res=0;
        bool valid=true;
        for(char&ch:text) {
            if(ch==' ') {																				// If ' ' is found, we process valid var.
                if(valid) res++;																		// If prev. word is valid(no broken chars), we inc. the fully typable words count.
                valid=true;																				// Resetting the valid var to true before moving to next word/char.
            }else if(broken[ch-'a']) valid=false;														// If broken char is encountered, we mark curr. word as invalid to fully type.
        }
        if(valid) res++;																				// This check will ensure last word is also processed.
        return res;																						// Return the fully typable words count.
    }
};

