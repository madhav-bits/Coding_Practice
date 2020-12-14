/*
*
//**********************************************1684. Count the Number of Consistent Strings.*******************************************

https://leetcode.com/problems/count-the-number-of-consistent-strings/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

# Worked on test cases provided with question.
"ab"
["ad","bd","aaab","baa","badab"]
"abc"
["a","b","c","ab","ac","bc","abc"]


// Time Complexity: O(n*m).													// n- #words in array, m-avg .length of words in array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n- #words in array, m-avg .length of words in array.
// Space Complexity: O(1).	
// This algorithm is Array based. Here, we store the character's presence in an array. We iter. over all strings, at each string, 
// we iter. over all chars, if we encounter a char which isn't a allowed char, we don't count that word into final result. In this 
// way, we get count of #words with allowed chars.








class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        vector<bool>isPresent(26,false);
        for(char ch: allowed) isPresent[ch-'a']=true;						// Marks allowed chars.
        for(int i=0;i<words.size();i++){
            int j=0;
            bool cnt=true;													// Tracks whether all chars in word are allowed.
            while(cnt && j<words[i].length()) cnt&=isPresent[words[i][j++]-'a'];
            res+=cnt;														// Inc. the cnt, if all chars are allowed.
        }
        return res;															// Return the #words with allowed chars.
    }
};