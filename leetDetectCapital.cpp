/*
*
//**********************************************************520. Detect Capital.***************************************************

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"USA"
"a"
"A"
"usa"
"usA"
"USa"
"sUA"
"FFf"
"fFF"
"FFfFFF"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we have two fail scenarios, Capital alphabets following Small alphabets starting index=1. Small alpha
// following Capital alphabets starting index=2. If these two scenarios are not found, return true.






class Solution {
public:
    bool detectCapitalUse(string word) {
        bool res;
        if(word.length()==1) return true;
        for(int i=1;i<word.length();i++){
            if(word[i]>=65 && word[i]<=90 && (word[i-1]>=97 && word[i-1]<=122)) return false;   		// Capital following small alphabets.
            if(i>1 && word[i]>=97 && word[i]<=122 && (word[i-1]>=65 && word[i-1]<=90)) return false;	// Small follo Capital alhabets from 2-index.
        }
        return true;																					// If no scenarios found, return true.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we need to have same types(small/large) for all chars starting from index=1. We check if first alpha.
// is Small and second alpha is Capital, if it is return false. If not we will check that, all index's types starting from 2 are same type
// as index=1, if not return false.




class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==1) return true;											// IF length==1, return true.
        bool cap1=(word[0]>=65 && word[0]<=90)?true:false;							// Calc. type of first index.
        bool cap2=(word[1]>=65 && word[1]<=90)?true:false;							// Calc. type of second index.
        if(!cap1 && cap2) return false;												// If first is small and second char is Capital, return false.
        for(int i=2;i<word.length();i++){
            bool temp=(word[i]>=65 && word[i]<=90)?true:false;						// Calc. type of curr. index.
            if(temp!=cap2) return false;											// If curr. type is not same as second index's type, ret. false
        }
        return true;																// If fail cases aren't encountered, return true.
    }
};