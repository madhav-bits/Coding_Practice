/*
*
//******************************************************2114. Maximum Number of Words Found in Sentences.******************************************************

https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["alice and bob love leetcode","i think so too","this is great thanks very much"]
["please wait", "continue to fight", "continue to win"]
["a","a b c def","please wait"]



// Time Complexity: O(n).																				// n-Combined length of all the strings.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n-Combined length of all the strings.
// Space Complexity: O(1).	
// This algorithm is iteration based. Since the words in the sentences are separated by single ' ' char with no leading and trailing spaces, we can count number of space chars and add one to get #words in a sentence and try to 
// maximize #maxWords in a sentence var and return it at end of iter.







class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res=0;
        for(string&s:sentences) {
            int temp=0;
            for(char&ch:s) {																			// Iter. over a string and counting #space bars.
                if(ch==' ') temp++;
            }
            temp++;																						// Inc. by 1 to reflect #words in the sentence.
            if(temp>res) res=temp;																		// Tracking max #words in a sentence.
        }
        return res;																						// Returning max #words in a sentence.
    }
};

