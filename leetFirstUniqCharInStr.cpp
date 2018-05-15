/*
*
//******************************************************387. First Unique Character in a String.***********************************************

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"aa"
""
"bbcdd"
"bbcdee"
"bbdceed"


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is masking/dyeing based. We maintain a vector of 26 length indicating each char. One dye(INT_MAX) alphabet not occured,
// Other dye(INT_MAX-1) for alphabets occured twice and else are given the indices where they actually occur(only once). In the second iteration
// of the vector, we return the minm value, if the extracted val. is INT_MAX/INT_MAX-1, then there is no char which occured only once, so we
// return -1 else we return the obtained value.



class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26,INT_MAX);																		// Tracks occur. of all chars.
        for(int i=0;i<s.length();i++){
            if(v[s[i]-'a']==INT_MAX) v[s[i]-'a']=i;														// Tracking first occurance of char.
            else if(v[s[i]-'a']<s.length()) v[s[i]-'a']=INT_MAX-1;										// Tracks second occurance of char.
        }
        int minm=INT_MAX;
        for(int i=0;i<26;i++){																			// Extracts the min. value of vector.
            minm=min(minm, v[i]);
        }
        
        return minm>=s.length()?-1:minm;																// If the min. is INT_MAX/INT_MAX-1, return
    }																									// -1, else return the obtained min value.
};