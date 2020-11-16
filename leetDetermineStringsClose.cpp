/*
*
//**********************************************1657. Determine if Two Strings Are Close.***********************************************

https://leetcode.com/problems/determine-if-two-strings-are-close/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked on test cases provided with the question.
"abc"
"bca"
"a"
"aa"
"cabbba"
"abbccc"
"cabbba"
"aabbss"
"abba"
"abab"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Observation based. Here,we store the #occur. of each char in both the strings, we also track the different 
// chars that occured in both the strings. Here, we are matching chars, the #chars with same freq has to match in both strings.
// Since we are swapping chars, they have to occur in both strings.








class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        vector<int>occur1(26,0), occur2(26,0);								// Tracks #occur. of each char in both strings.
        vector<bool>pres1(26, false), pres2(26, false);						// Tracks chars which occur. in both strings.
        for(int i=0;i<word1.length();i++){
            occur1[word1[i]-'a']++;											// Tracking the #occur. of curr. char.
            occur2[word2[i]-'a']++;
            
            pres1[word1[i]-'a']=true;										// Marking that curr. char has occured.
            pres2[word2[i]-'a']=true;
        }
        sort(occur1.begin(), occur1.end());									// Sorting the freq. of chars.
        sort(occur2.begin(), occur2.end());
        return (occur1==occur2) && (pres1==pres2);							// Matching freq. of chars and occur. of chars in both strs.
    }
};