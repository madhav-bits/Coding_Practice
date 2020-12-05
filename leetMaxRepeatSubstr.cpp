/*
*
//************************************************1668. Maximum Repeating Substring.**************************************************

https://leetcode.com/problems/maximum-repeating-substring/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



"ababc"
"ab"
"ababc"
"ba"
"abeabeababeab"
"abeab"


// Time Complexity: O(n*m^2).													// n- length of string, m-length of word.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m^2).													// n- length of string, m-length of word.
// Space Complexity: O(n).	
// This algorithm is string based. Here, we find the temp word in the given string. At every step we append the given word to temp word
// to make it repeating seq. of itself. We repeat this process until we are able to find the repeated word in the given str. We return
// the repeating count at the end of process.







class Solution {
public:
    int maxRepeating(string s, string word) {	
        int res=0;															// Repeat of given word we can find in given string.
        string temp=word;													// Temp. word we search in given string.
        while(s.find(temp)!=string::npos){
            res++;
            temp+=word;														// Result str based on repeating.
        }
        return res;															// Returning the repeat of given word in given string.
    }
};