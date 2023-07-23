/*
*
//******************************************************2788. Split Strings by Separator.******************************************************

https://leetcode.com/problems/split-strings-by-separator/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["one.two.three","four.five","six"]
"."
["$easy$","$problem$"]
"$"
["|||"]
"|"



// Time Complexity: O(n*m).													// n-length of the array, m-avg. length of the string.				
// Space Complexity: O(l).													// l-max. length of the string.	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n-length of the array, m-avg. length of the string.				
// Space Complexity: O(l).													// l-max. length of the string.	
// This algorithm is iteration based. We maintain temp array to store chars in b/w two separators, when we encouner a separator or reach end of string, we
// check the temp string for it's length, if it's non-empty, we add temp str to res and reset it to empty string, we iter. over all strings in the array this
// way and return res array at the end of iter.






class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
        vector<string>res;
        string temp="";
        for(string& word:words) {
            for(char&ch:word) {
                if(ch==sep) {												// When we encounter a separator.
                    if(temp.length()>0) res.push_back(temp);				// If temp string is non-empty, we add it to res.
                    temp="";
                } else temp+=ch;
            }
            if(temp.length()>0) res.push_back(temp);						// We add non-empty temp string to res at the end of curr. string.
            temp="";
        }
        return res;															// Returning all substrings separated by separators.
    }
};

