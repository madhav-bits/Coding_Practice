/*
*
//********************************************1662. Check If Two String Arrays are Equivalent.******************************************

https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


["ab", "c"]
["a", "bc"]


["abc", "cde"]
["a", "bc","cde"]



// Time Complexity: O(m+n).													// m,n - Sum of all strings len in word, word2.
// Space Complexity: O(m+n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).													// m,n - Sum of all strings len in word, word2.
// Space Complexity: O(m+n).	
// This algorithm is iteration based. Here, we form the string formed because of cocatenation on both sides. We compare those strings, 
// if equal, we return true else return false.








class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="", t="";
        for(auto word:word1)
            s+=word;
        for(auto word:word2)
            t+=word;
        return (s==t);
    }
};