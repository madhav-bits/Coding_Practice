/*
*
//***********************************************2255. Count Prefixes of a Given String.*********************************************

https://leetcode.com/problems/count-prefixes-of-a-given-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["a","b","c","ab","bc","abc"]
"abc"
["a","abcd","b","c","ab","bc","abc"]
"abc"
["a","a"]
"aa"



// Time Complexity: O(n*m).													//n-#strs in the array, m-avg. length of strings in the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													//n-#strs in the array, m-avg. length of strings in the array.
// Space Complexity: O(1).	
// This algorithm is iteration based. For every string in array, we parallelly iterate on both the str and target str and check whether if they have same chars 
// until we reach end of string in arr. If we reached end of string with all matching chars, that means curr. str is prefix of target str and we inc. res by 1.
// We skip checking strs whose lenthgs are greater than target str as they can't be prefixes. We return res at the end of iter.







class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res=0;
        for(string&t:words) {												// Iter. over all strings in the array.
            if(t.length()>s.length()) continue;								// Skipping greater length strings as they can't be prefix of 's'.
            int i=0;
            while(i<t.length() && t[i]==s[i]) i++;							// We iter. as long as chars are equal.
            if(i==t.length()) res++;										// If we match all chars in given str, then it's prefix.
        }	
        return res;															// Returning #prefix strs in the given array.
    }
};

